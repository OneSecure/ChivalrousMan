#include"PlayerListLayer.h"
#include"Commen.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"PlayerItem.h"
#include"CMClient.h"

bool PlayerListLayer::init()
{
	if (Layer::init())
	{
		LISTEN_TOUCH(PlayerListLayer);
		auto size = SCREEN;
		auto bg = Sprite::create(StringValue("PlayerListBg"));
		bg->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(bg);
		
		auto titlelabel = LabelTTF::create(StringValue("NearPlayerText"), "¿¬Ìå", 30);
		titlelabel->setColor(Color3B::YELLOW);
		titlelabel->setPosition(size.width*0.5, bg->getPositionY() + bg->getContentSize().height*0.5 - 25);
		this->addChild(titlelabel);
		
		m_basePos = bg->getPosition();
		initPlayerItem();

		auto scrollbarBg = Sprite::create(StringValue("ScrollBarBg"));
		scrollbarBg->setPosition(bg->getPositionX() + bg->getContentSize().width*0.5 - 20, size.height*0.5-5);
		this->addChild(scrollbarBg);

		auto menu = Menu::create();
		menu->setPosition(0, 0);
		this->addChild(menu);
		m_topPos = ccp(scrollbarBg->getPositionX(), scrollbarBg->getPositionY() + scrollbarBg->getContentSize().height*0.5 - 30);
		m_bottomPos = ccp(scrollbarBg->getPositionX(), scrollbarBg->getPositionY() - scrollbarBg->getContentSize().height*0.5 + 30);
		m_scrollBar = MenuItemImage::create(StringValue("ScrollBar"), StringValue("ScrollBar"), this,
			menu_selector(PlayerListLayer::onScrollBarClick));
		m_scrollBar->setPosition(m_topPos);
		menu->addChild(m_scrollBar);

		return true;
	}
	return false;
}

void PlayerListLayer::initPlayerItem()
{
	m_basePos.x -= 15;
	m_basePos.y += 190;
	int index = 0;
	/*for (int i = 0; i < 15; ++i)
	{
		Player_Info info;
		info.rolename = "hahhaha" + NTS(i);
		info.grade = i + 1;
		info.playertype = "Player2";
		auto item = PlayerItem::create(info);
		item->setPosition(m_basePos.x, m_basePos.y - i * 80);
		this->addChild(item);
		m_itemlist.push_back(item);
		if (i >5)
		{
			item->setVisible(false);
		}
	}*/
	for (auto var : CMClient::getInstance()->getPlayerList())
	{
		if (var.curmap == GetIntData("CurMap"))
		{
			auto item = PlayerItem::create(var);
			item->setPosition(m_basePos.x, m_basePos.y + index * 82);
			this->addChild(item);
			m_itemlist.push_back(item);
			++index;
			if (index > 6)
			{
				item->setVisible(false);
			}
		}
	}
}

bool PlayerListLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	m_dy = 0;
	m_click = true;
	m_startPos = touch->getLocation();
	m_startScrollPos = m_scrollBar->getPosition();
	return Layer::onTouchBegan(touch, unused_event);
}

void PlayerListLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	m_scrollClick = false;
	m_click = false;
	recoverItem(m_dy);
}

void PlayerListLayer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	if (m_click||m_scrollClick)
	{
		float dy = touch->getLocation().y - m_startPos.y;
		auto y = m_startScrollPos.y + dy;
		y > m_topPos.y ? y = m_topPos.y : 1;
		y < m_bottomPos.y ? y = m_bottomPos.y : 1;
		m_scrollBar->setPosition(m_startScrollPos.x, y);
		moveItem(dy / 20);
	}
}

void PlayerListLayer::onScrollBarClick(cocos2d::CCObject* sender)
{
	m_scrollClick = true;
}

void PlayerListLayer::moveItem(float dy)
{
	if (m_itemlist.size() <6)
	{
		return;
	}
	float y = 0;
	if (dy < 0)
	{
		if (m_itemlist[0]->getPositionY() < m_basePos.y)
		{
			m_dy = m_basePos.y - m_itemlist[0]->getPositionY();
			if (m_dy >=40)
			{
				m_dy = 40;
				return;
			}
		}
	}
	else
	{
		if (m_itemlist[m_itemlist.size() - 1]->getPositionY() > m_basePos.y - 400)
		{
			m_dy = (m_basePos.y - 400) - m_itemlist[m_itemlist.size() - 1]->getPositionY();
			if (m_dy <= -40)
			{
				m_dy = -40;
				return;
			}
		}
	}
	for(int i=0;i<m_itemlist.size();++i)
	{
		y =  m_itemlist[i]->getPositionY() + dy;
		m_itemlist[i]->setPositionY(y);
		if (y > m_basePos.y + 40 || y < m_basePos.y - 440)
		{
			m_itemlist[i]->setVisible(false);
		}
		else
		{
			m_itemlist[i]->setVisible(true);
		}
	}
}

void PlayerListLayer::recoverItem(float dy)
{
	float y = 0;
	for (auto var : m_itemlist)
	{
		MoveBy* move = MoveBy::create(0.2, ccp(0, dy));
		y=var->getPositionY() + dy;
		var->runAction(move);
		if (y> m_basePos.y + 40 || y < m_basePos.y - 440)
		{
			var->setVisible(false);
		}
		else
		{
			var->setVisible(true);
		}
	}
}
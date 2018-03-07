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
		
		initPlayerItem(bg->getPosition());

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
		m_scrollBar->setPosition(m_bottomPos);
		menu->addChild(m_scrollBar);

		return true;
	}
	return false;
}

void PlayerListLayer::initPlayerItem(cocos2d::Vec2 basePos)
{
	basePos.x -= 15;
	basePos.y += 190;
	int index = 0;
	for (int i = 0; i < 6; ++i)
	{
		Player_Info info;
		info.rolename = "hahhaha";
		info.grade = 3;
		info.playertype = "Player2";
		auto item = PlayerItem::create(info);
		item->setPosition(basePos.x, basePos.y - i * 80);
		this->addChild(item);
		m_itemlist.push_back(item);
	}
	//for (auto var : CMClient::getInstance()->getPlayerList())
	//{
	//	if (var.curmap == GetIntData("CurMap"))
	//	{
	//		auto item = PlayerItem::create(var);
	//		item->setPosition(basePos.x, basePos.y + index * 82);
	//		this->addChild(item);
	//		++index;
	//	}
	//}
}

void PlayerListLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	
}

void PlayerListLayer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	
}

void PlayerListLayer::onScrollBarClick(cocos2d::CCObject* sender)
{
	
}
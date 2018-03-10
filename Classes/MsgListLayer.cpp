#include"MsgListLayer.h"
#include"Commen.h"
#include"GameData.h"
#include"MsgItem.h"
#include"PrivateTalkLayer.h"
#include"GameDynamicData.h"
#include"GameScene.h"
#include"CMClient.h"
#include<functional>

bool MsgListLayer::init()
{
	if (Layer::init())
	{
		auto size = SCREEN;
		setName("MsgListLayer");
		auto bg = Sprite::create(StringValue("MsgListBg"));
		bg->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(bg);

		auto titlelabel = LabelTTF::create(StringValue("MsgListText"), "¿¬Ìå", 30);
		titlelabel->setColor(Color3B::YELLOW);
		titlelabel->setPosition(bg->getPositionX(), bg->getPositionY() + bg->getContentSize().height*0.5 - 20);
		this->addChild(titlelabel);

		initMsgItem(ccp(bg->getPositionX(), bg->getPositionY() + bg->getContentSize().height*0.5));
		return true;
	}
	return false;
}

void MsgListLayer::initMsgItem(cocos2d::Vec2 basePos)
{
	auto menu = Menu::create();
	menu->setPosition(0, 0);
	this->addChild(menu);
	basePos.y -= 75;
	int index = 0;
	for (const auto& var:CMClient::getInstance()->getPrivateMsgs())
	{
		auto item = MsgItem::create(var.first);
		item->setTarget(this, menu_selector(MsgListLayer::onItemClickCallback));
		item->setPosition(basePos.x, basePos.y - index * 80);
		menu->addChild(item);
		m_itemlist.push_back(item);
		++index;
	}
}

void MsgListLayer::onItemClickCallback(cocos2d::CCObject* sender)
{
	auto move = ScaleTo::create(0.1, 1.05);
	auto move1 = ScaleTo::create(0.1, 1.0);
	((MenuItemImage*)sender)->runAction(Sequence::createWithTwoActions(move, move1));
	std::function<void(float)> func = [this, sender](float) {
		int fd = ((MsgItem*)sender)->getFd();
		CMClient::getInstance()->getPrivateMsgs()[fd][0].change = false;
		((MsgItem*)sender)->setRedSpot(false);
		auto ptlayer = PrivateTalkLayer::create(fd);
		CurGameScene()->addChild(ptlayer);
		this->setVisible(false);
	};
	scheduleOnce(func, 0.22, "ptkey");
}

void MsgListLayer::removeMsgItem(MsgItem* item)
{
	int flag = 0;
	for (auto it = m_itemlist.begin(); it != m_itemlist.end();)
	{
		if ((*it) == item)
		{
			it=m_itemlist.erase(it);
			flag = 1;
		}
		else
		{
			if (flag)
			{
				auto move = MoveBy::create(0.2, ccp(0, 80));
				(*it)->runAction(move);
			}
			++it;
		}
	}
	item->getParent()->removeChild(item);
}
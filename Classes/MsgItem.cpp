#include"MsgItem.h"
#include"Commen.h"
#include"GameData.h"
#include"CMClient.h"
#include"MsgListLayer.h"
#include<functional>

MsgItem* MsgItem::create(const int& fd)
{
	auto pRet = new MsgItem;
	if (pRet&&pRet->init(fd))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool MsgItem::init(const int& fd)
{
	if (MenuItemImage::init())
	{
		m_fd = fd;
		auto bg = Sprite::create(StringValue("MsgItemBg"));
		this->setNormalImage(bg);
		this->setSelectedImage(bg);
		this->setDisabledImage(bg);

		auto info = CMClient::getInstance()->findPlayerInfoByFd(fd);
		auto headFrame = Sprite::create(StringValue("HeadFrame"));
		headFrame->setPosition(40, 30);
		headFrame->setScale(0.8, 0.8);
		this->addChild(headFrame);
		auto head = MenuItemImage::create(StringValue(info.playertype + "Head"),
			StringValue(info.playertype + "Head"));
		head->setPosition(headFrame->getPosition().x - 5, headFrame->getPosition().y + 10);
		this->addChild(head);
		
		auto namelabel = LabelTTF::create(info.rolename, "¿¬Ìå", 16);
		namelabel->setAnchorPoint(ccp(0, 0.5));
		namelabel->setPosition(head->getPositionX() + 34, 45);
		this->addChild(namelabel);

		auto gradelabel = LabelTTF::create(StringValue("GradeText") + NTS(info.grade), "¿¬Ìå", 16);
		gradelabel->setAnchorPoint(ccp(0, 0.5));
		gradelabel->setColor(Color3B::ORANGE);
		gradelabel->setPosition(head->getPositionX() + 34, 15);
		this->addChild(gradelabel);

		bool flag = CMClient::getInstance()->getPrivateMsgs()[fd][0].change;
		m_redspot = Sprite::create(StringValue("MsgTip"));
		m_redspot->setPosition(bg->getPositionX() + bg->getContentSize().width - 20, 50);
		this->addChild(m_redspot);
		m_redspot->setVisible(flag);

		auto menu = Menu::create();
		menu->setPosition(0, 0);
		this->addChild(menu);
		auto delBtn = MenuItemImage::create(StringValue("DelBtn"), StringValue("DelBtn"),
			this, menu_selector(MsgItem::onDeleteBtnClick));
		delBtn->setPosition(bg->getPositionX() + bg->getContentSize().width - 25, 20);
		menu->addChild(delBtn);
		return true;
	}
	return false;
}

void  MsgItem::onDeleteBtnClick(cocos2d::CCObject* sender)
{
	ClickAction(sender);
	std::function<void(float)> func = [this](float) {
		((MsgListLayer*)(this->getParent()->getParent()))->removeMsgItem(this);
	};
	scheduleOnce(func, 0.1, "key");
}

void MsgItem::setRedSpot(bool b)
{
	m_redspot->setVisible(b);
}
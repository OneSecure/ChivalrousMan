#include"PlayerItem.h"
#include"Commen.h"
#include"GameData.h"
#include"ShareData.h"

PlayerItem* PlayerItem::create(const Player_Info& info)
{
	PlayerItem* pRet = new PlayerItem;
	if (pRet&&pRet->init(info))
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

bool PlayerItem::init(const Player_Info& info)
{
	if (Node::init())
	{
		auto bg = Sprite::create(StringValue("PlayerItemBg"));
		this->addChild(bg);

		auto menu = Menu::create();
		menu->setPosition(0, 0);
		this->addChild(menu);
		auto headFrame = Sprite::create(StringValue("HeadFrame"));
		headFrame->setPosition(-80, 0);
		headFrame->setScale(0.8, 0.8);
		this->addChild(headFrame);
		auto head = MenuItemImage::create(StringValue(info.playertype + "Head"),
			StringValue(info.playertype + "Head"), this,
			menu_selector(PlayerItem::onHeadClick));
		head->setPosition(headFrame->getPosition().x - 5, headFrame->getPosition().y + 5);
		menu->addChild(head);

		auto namelabel = LabelTTF::create(info.rolename, "¿¬Ìå", 16);
		namelabel->setAnchorPoint(ccp(0, 0.5));
		namelabel->setPosition(head->getPositionX() + 34, 18);
		this->addChild(namelabel);

		auto gradelabel = LabelTTF::create(StringValue("GradeText") + NTS(info.grade), "¿¬Ìå", 16);
		gradelabel->setAnchorPoint(ccp(0, 0.5));
		gradelabel->setColor(Color3B::ORANGE);
		gradelabel->setPosition(head->getPositionX() + 34, -15);
		this->addChild(gradelabel);
		
		auto ptalkBtn = MenuItemImage::create(StringValue("PrivateTalkBtn"),
			StringValue("PrivateTalkBtn"), this, menu_selector(PlayerItem::onPrivateTalkClick));
		ptalkBtn->setPosition(80, 15);
		menu->addChild(ptalkBtn);
		
		auto maketeamBtn = MenuItemImage::create(StringValue("MakeTeamBtn"),
			StringValue("MakeTeamBtn"), this, menu_selector(PlayerItem::onMakeTeamClick));
		maketeamBtn->setPosition(80, -15);
		menu->addChild(maketeamBtn);
		m_fd = info.fd;
		return true;
	}
	return false;
}

void PlayerItem::onHeadClick(cocos2d::CCObject* sender)
{
	ClickAction(sender);
}

void PlayerItem::onPrivateTalkClick(cocos2d::CCObject* sender)
{
	ClickAction(sender);
}

void PlayerItem::onMakeTeamClick(cocos2d::CCObject* sender)
{
	ClickAction(sender);
}
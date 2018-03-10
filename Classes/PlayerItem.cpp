#include"PlayerItem.h"
#include"Commen.h"
#include"GameData.h"
#include"ShareData.h"
#include"GameDynamicData.h"
#include"GameScene.h"
#include"PrivateTalkLayer.h"
#include"CMClient.h"

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
		ITEM_COMMEN(PlayerItem, StringValue("PlayerItemBg"), -80);
		
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
	auto ptlayer = PrivateTalkLayer::create(m_fd);
	CurGameScene()->addChild(ptlayer);
	getParent()->setVisible(false);
}

void PlayerItem::onMakeTeamClick(cocos2d::CCObject* sender)
{
	ClickAction(sender);
	TeamApply_Msg msg;
	msg.dest = m_fd;
	CMClient::getInstance()->SendMsg((char*)&msg, sizeof(msg));
}
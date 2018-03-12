#include"MemberItem.h"
#include"Commen.h"
#include"GameData.h"
#include"TeamManager.h"
#include"TeamLayer.h"
#include"CMClient.h"

#define DISSOLVE_TEAM()    \
for (auto var : TeamManager::getInstance()->getTeamMembers())  \
{   \
	CMClient::getInstance()->SendTeamDissolveMsg(var.first);   \
}  \
TeamManager::getInstance()->dissolveTeam()

MemberItem* MemberItem::create(const Player_Info& info,const int& status, const int& btn_status)
{
	auto pRet = new MemberItem;
	if (pRet&&pRet->init(info,status,btn_status))
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

bool MemberItem::init(const Player_Info& info,const int& status, const int& btn_status)
{
	if (Node::init())
	{
		ITEM_COMMEN(MemberItem, StringValue("MsgItemBg"), -110);
		
		std::string statusStr = status == P_STATUS_HEADER ? StringValue("TeamHeaderText") : StringValue("TeamMemberText");
		auto statuslabel = LabelTTF::create(statusStr, "¿¬Ìå", 20);
		statuslabel->setColor(Color3B::RED);
		this->addChild(statuslabel);

		if (TB_NULL != btn_status)
		{
			MenuItemImage* btn;
			switch (btn_status)
			{
			case TB_DISSOLVE:
				btn=MenuItemImage::create(StringValue("DissolveTeamBtn"), StringValue("DissolveTeamBtn"),
					this, menu_selector(MemberItem::onDissolveBtnClick));
				break;
			case TB_KICKOUT:
				btn=MenuItemImage::create(StringValue("KickOutTeamBtn"), StringValue("KickOutTeamBtn"),
					this, menu_selector(MemberItem::onKickOutBtnClick));
				break;
			case TB_QUIT:
				btn=MenuItemImage::create(StringValue("QuitTeamBtn"), StringValue("QuitTeamBtn"),
					this, menu_selector(MemberItem::onQuitTeamBtnClick));
				break;
			}
			btn->setPosition(110, 0);
			menu->addChild(btn);
		}
		return true;
	}
	return false;
}

void MemberItem::onHeadClick(cocos2d::CCObject* sender)
{
	ClickAction(sender);
}

void MemberItem::onDissolveBtnClick(cocos2d::CCObject* sender)
{
	ClickAction(sender);
	DISSOLVE_TEAM();
	((TeamLayer*)getParent())->removeMsgItem(this);
}

void MemberItem::onKickOutBtnClick(cocos2d::CCObject* sender)
{
	ClickAction(sender);
	DISSOLVE_TEAM();
	((TeamLayer*)getParent())->removeMsgItem(this);
}

void MemberItem::onQuitTeamBtnClick(cocos2d::CCObject* sender)
{
	ClickAction(sender);
	DISSOLVE_TEAM();	
	((TeamLayer*)getParent())->removeMsgItem(this);
}
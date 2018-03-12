#include"TeamLayer.h"
#include"Commen.h"
#include"GameData.h"
#include"CameraPlayer.h"
#include"TeamMsgItem.h"
#include"MemberItem.h"
#include"GameDynamicData.h"
#include"CameraPlayer.h"
#include"TeamManager.h"
#include"CMClient.h"

bool TeamLayer::init()
{
	if (Layer::init())
	{
		auto size = SCREEN;
		setName("TeamLayer");
		auto bg = Sprite::create(StringValue("MsgListBg"));
		bg->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(bg);
		
		std::string nametext;
		Vec2 pos = bg->getPosition();
		pos.y = pos.y + bg->getContentSize().height*0.5 - 80;
		if (PlayerTeamStatus() == P_STATUS_NORMAL)
		{
			nametext = StringValue("ApplyListText");
			initApplyList(pos);
		}
		else
		{
			nametext = StringValue("MemberText");
			initTeamMember(pos);
		}
		auto namelabel = LabelTTF::create(nametext, "¿¬Ìå", 30);
		namelabel->setColor(Color3B::YELLOW);
		namelabel->setPosition(bg->getPositionX(), bg->getPositionY() + bg->getContentSize().height*0.5 - 18);
		this->addChild(namelabel);
		return true;
	}
	return false;
}

void TeamLayer::initApplyList(const cocos2d::Vec2& basePos)
{
	int index = 0;
	for (auto var : CMClient::getInstance()->getApplyTeamList())
	{
		auto item = TeamMsgItem::create(var);
		item->setPosition(basePos.x, basePos.y - index * 80);
		this->addChild(item);
		m_itemlist.push_back(item);
		++index;
	}
}

void TeamLayer::initTeamMember(const cocos2d::Vec2& basePos)
{
	Player_Info info;
	info.rolename = GetStringData("rolename");
	info.grade = GetPlayerData().getgrade();
	info.playertype = GetStringData("PlayerType");
	MemberItem* item = MemberItem::create(info, PlayerTeamStatus(), PlayerTeamStatus() == P_STATUS_HEADER ? TB_DISSOLVE : TB_QUIT);
	item->setPosition(basePos);
	m_itemlist.push_back(item);
	this->addChild(item);
	int index = 1;
	for (auto var : TeamManager::getInstance()->getTeamMembers())
	{
		info = CMClient::getInstance()->findPlayerInfoByFd(var.first);
		item = MemberItem::create(info, var.second, PlayerTeamStatus() == P_STATUS_HEADER ? TB_KICKOUT : TB_NULL);
		item->setPosition(basePos.x, basePos.y - index * 80);
		this->addChild(item);
		m_itemlist.push_back(item);
		++index;
	}
}

void TeamLayer::removeMsgItem(cocos2d::Node* item)
{
	int flag = 0;
	for (auto it = m_itemlist.begin(); it != m_itemlist.end(); )
	{
		if ((*it) == item)
		{
			this->removeChild(*it);
			it = m_itemlist.erase(it);
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
}
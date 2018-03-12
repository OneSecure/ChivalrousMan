#include"CMClient.h"
#include"GameData.h"
#include"Commen.h"
#include"GameDynamicData.h"
#include"CameraPlayer.h"
#include"GameScene.h"
#include"ObjectLayer.h"
#include"GameUILayer.h"
#include"PrivateTalkLayer.h"
#include"TeamManager.h"
#include"TipLayer.h"
#include"FightLayer.h"
#include<fstream>
#include<string>

using namespace Net;

DEFINE_SINGLE_ATTRIBUTES(CMClient);

CMClient::CMClient()
{
	readConfConnectServer();
}

CMClient::~CMClient()
{

}

void CMClient::release()
{
	RELEASE_NULL(m_instance);
}


void  CMClient::OnRecv(char* buff)
{
	if (!strcmp(buff, CLOSE_MESSAGE))
	{
		MessageBox("服务器异常关闭", "提示");
		Director::getInstance()->end();
	}
	M_Type type = *((M_Type*)buff);
	switch (type)
	{
	case M_EntryGame:
		break;
	case M_InitData:
	{
		doInitMsg((InitData_Msg*)buff);
	}
		break;
	case M_WorldTalk:
	{
		addWorldTalkMsg((WorldTalk_Msg*)buff);
	}
		break;
	case M_PrivateTalk:
		addPrivateTalkMsg((PrivateTalk_Msg*)buff);
		break;
	case M_InitPos:
		doInitPlayerPosMsg((InitPos_Msg*)buff);
		break;
	case M_PlayerLeave:
	{
		doPlayerLeaveMsg((PlayerLeave_Msg*)buff);
	}
		break;
	case M_MoveTo:
		doPlayerMoveToMsg((MoveTo_Msg*)buff);
		break;
	case M_VerifyPos:
		doPlayerPosVerifyMsg((VerifyPos_Msg*)buff);
		break;
	case M_UpdateData:
		doPlayerDataUpdaeMsg((UpdateData_Msg*)buff);
		break;
	case M_TeamApply:
	{
		doTeamApplyMsg((TeamApply_Msg*)buff);
	}
		break;
	case M_RefuseTeam:
		doRefuseTeamMsg((RefuseTeam_Msg*)buff);
		break;
	case M_AgreeTeam:
		doAgreeTeamMsg((AgreeTeam_Msg*)buff);
		break;
	case M_TeamMove:
		doTeamMoveMsg((TeamMove_Msg*)buff);
		break;
	case M_TeamGotoMap:
		doTeamGotoMapMsg((TeamGotoMap_Msg*)buff);
		break;
	case M_DissolveTeam:
		doTeamDissolveMsg();
		break;
	case M_TeamFight:
		doTeamFightMsg((TeamFight_Msg*)buff);
		break;
	default:
		break;
	}
}

void CMClient::readConfConnectServer()
{
	std::ifstream fin;
	fin.open(StringValue("ServerConf"), std::ios::in);
	if (fin.fail())
	{
		return;
	}
	std::string tmp;
	
	fin >> m_serverip;

	fin >> m_serverip;
	fin >> m_serverip;
	fin >> tmp;
	fin >> m_port;

	fin.close();
}

int CMClient::Connect()
{
	return CTCPClient::ConnectSever(m_serverip, m_port);
}

void CMClient::SendInitPlayerData()
{
	m_playerlist.clear();
	InitData_Msg msg;
	msg.type = M_InitData;
	strcpy_s(msg.playername, GetStringData("playername").c_str());
	strcpy_s(msg.rolename, GetStringData("rolename").c_str());
	strcpy_s(msg.playertype, GetStringData("PlayerType").c_str());
	msg.curmap = GetIntData("CurMap");
	msg.attack = GetPlayerData().getattack();
	msg.blood = GetPlayerData().getblood();
	msg.defense = GetPlayerData().getdefense();
	msg.mana = GetPlayerData().getmana();
	msg.grade = GetPlayerData().getgrade();
	msg.fd = -1;
	SendMsg((char*)&msg, sizeof(msg));
}

void CMClient::SendInitPos()
{
	InitPos_Msg msg;
	msg.type = M_InitPos;
	msg.x = PlayerPos.x;
	msg.y = PlayerPos.y;
	msg.fd = -1;
	msg.curmap = GetIntData("CurMap");
	SendMsg((char*)&msg, sizeof(msg));
}

void CMClient::doInitMsg(InitData_Msg* msg)
{
	Player_Info pinfo;
	pinfo.playername = msg->playername;
	pinfo.attack = msg->attack;
	pinfo.blood = msg->blood;
	pinfo.curmap =msg->curmap;
	pinfo.defense = msg->defense;
	pinfo.mana = msg->mana;
	pinfo.playertype = msg->playertype;
	pinfo.rolename = msg->rolename;
	pinfo.fd = msg->fd;
	pinfo.grade = msg->grade;
	m_playerlist.push_back(pinfo);
}

void CMClient::doInitPlayerPosMsg(InitPos_Msg* msg)
{
	for (auto var=m_playerlist.begin();var!=m_playerlist.end();++var)
	{
		if (msg->fd == var->fd)
		{
			var->x = msg->x;
			var->y = msg->y;
			var->curmap = msg->curmap;
			if (GetIntData("IsHaveGameScene") == 1)
				CurGameScene()->getObjectLayer()->addPlayer(*var);
		}
	}
}

void CMClient::SendPlayerLeaveMsg()
{
	PlayerLeave_Msg msg;
	msg.type = M_PlayerLeave;
	msg.fd = -1;
	SendMsg((char*)&msg, sizeof(msg));
}

void CMClient::doPlayerLeaveMsg(PlayerLeave_Msg* msg)
{
	removePlayer(msg->fd);
}

void CMClient::removePlayer(int fd)
{
	for (auto it = m_playerlist.begin(); it != m_playerlist.end(); ++it)
	{
		if (it->fd == fd)
		{
			if (GetIntData("IsHaveGameScene") == 1)
				CurGameScene()->getObjectLayer()->removePlayer(it->playername, it->rolename);
			TeamManager::getInstance()->removeTeamMembers(it->fd);
			m_privateTalkMsgs.erase(it->fd);
			m_playerlist.erase(it);
			return;
		}
	}
}

void CMClient::SendMoveToMsg(const cocos2d::Vec2& pos,int less)
{
	MoveTo_Msg msg;
	msg.type = M_MoveTo;
	msg.fd = -1;
	msg.x = pos.x;
	msg.y = pos.y;
	msg.less = less;
	SendMsg((char*)&msg, sizeof(msg));
}

void CMClient::doPlayerMoveToMsg(MoveTo_Msg* msg)
{
	Vec2 target{ msg->x,msg->y };
	for (auto var : m_playerlist)
	{
		if (var.fd == msg->fd)
		{
			if (GetIntData("IsHaveGameScene") == 1)
				CurGameScene()->getObjectLayer()->moveOtherPlayer(var.playername, var.rolename, target, msg->less);
		}
	}
}

void CMClient::doPlayerPosVerifyMsg(VerifyPos_Msg* msg)
{
	for (auto var=m_playerlist.begin();var!=m_playerlist.begin();++var)
	{
		if (var->fd == msg->fd)
		{
			var->x = msg->x;
			var->y = msg->y;
			if (GetIntData("IsHaveGameScene") == 1)
				CurGameScene()->getObjectLayer()->verifyPlayerPos(var->playername, var->rolename, Vec2{ msg->x,msg->y });
		}
	}
}

void CMClient::VerifyPlayerPos()
{
	VerifyPos_Msg msg;
	msg.type = M_VerifyPos;
	msg.x = PlayerPos.x;
	msg.y = PlayerPos.y;
	msg.fd = -1;
	SendMsg((char*)&msg, sizeof(msg));
}

void CMClient::updatePlayerData()
{
	UpdateData_Msg msg;
	msg.type = M_UpdateData;
	msg.attack = GetPlayerData().getattack();
	msg.blood = GetPlayerData().getblood();
	msg.defense = GetPlayerData().getdefense();
	msg.fd = -1;
	msg.grade = GetPlayerData().getgrade();
	msg.mana = GetPlayerData().getmana();
	SendMsg((char*)&msg, sizeof(msg));
}

void CMClient::doPlayerDataUpdaeMsg(UpdateData_Msg* msg)
{
	for (auto var =m_playerlist.begin();var!=m_playerlist.end();++var)
	{
		if (var->fd == msg->fd)
		{
			var->attack = msg->attack;
			var->defense = msg->defense;
			var->blood = msg->blood;
			var->grade=msg->grade;
			var->mana = msg->mana;
			if (GetIntData("IsHaveGameScene") == 1)
				CurGameScene()->getObjectLayer()->updatePlayerData(var->playername, var->rolename, *msg);
		}
	}
}

std::string CMClient::findRoleNameByFd(const int& fd)
{
	for(auto var:m_playerlist)
	{
		if (var.fd == fd)
		{
			return var.rolename;
		}
	}
	return "";
}

void CMClient::addWorldTalkMsg(WorldTalk_Msg* msg)
{
	TalkMsg tmsg;
	if (msg->fd != -1)
		tmsg.rolename = findRoleNameByFd(msg->fd);
	else
		tmsg.rolename = StringValue("Me");
	tmsg.msg = msg->msg;
	m_worldTalkMsgs.push_back(tmsg);
	if (m_worldTalkMsgs.size() > 100)
	{
		m_worldTalkMsgs.pop_front();
	}
	if (GetIntData("IsHaveGameScene") == 1)
		CurGameScene()->getGameUiLayer()->updateWorldTalkQueue(tmsg);
}

void CMClient::addPrivateTalkMsg(PrivateTalk_Msg* msg)
{
	TalkMsg tmsg;
	int realfd;
	if (msg->fd != -1)
	{
		tmsg.rolename = findRoleNameByFd(msg->fd);
		realfd = msg->fd;
	}
	else
	{
		tmsg.rolename = StringValue("Me");
		realfd = msg->dest;
	}
	tmsg.destname = findRoleNameByFd(realfd);
	if (tmsg.destname == "")
	{
		TipLayer* tplayer = TipLayer::createTipLayer(StringValue("OffLine"));
		if (GetIntData("IsHaveGameScene") == 1)
			CurGameScene()->addChild(tplayer);
		return;
	}
	tmsg.msg = msg->msg;
	if (m_privateTalkMsgs.find(realfd) != m_privateTalkMsgs.end())
	{
		if (m_privateTalkMsgs.size() >= 6)
			m_privateTalkMsgs.erase(m_privateTalkMsgs.begin());
	}
	m_privateTalkMsgs[realfd].push_back(tmsg);
	if (GetIntData("IsHaveGameScene") == 1)
	{
		PrivateTalkLayer* ptlayer = (PrivateTalkLayer*)CurGameScene()->getChildByName("PrivateTalkLayer");
		if (ptlayer != nullptr)
			ptlayer->addMsg(tmsg.rolename, tmsg.msg);
	}
	if (msg->fd != -1)
	{
		m_privateTalkMsgs[realfd][0].change = true;
		if (GetIntData("IsHaveGameScene") == 1)
			CurGameScene()->getGameUiLayer()->setRedSpot(true);
	}
	if (m_privateTalkMsgs[realfd].size() >18)
	{
		m_privateTalkMsgs[realfd].pop_front();
	}
}

Player_Info CMClient::findPlayerInfoByFd(const int& fd)
{
	Player_Info info;
	for (const auto& var : m_playerlist)
	{
		if (var.fd == fd)
		{
			return var;
		}
	}
	return info;
}

void CMClient::doTeamApplyMsg(TeamApply_Msg* msg)
{
	m_applyTeamList.push_back(msg->fd);
	if (m_applyTeamList.size() > 6)
	{
		m_applyTeamList.pop_front();
	}
	if (GetIntData("IsHaveGameScene") == 1)
	{
		CurGameScene()->getGameUiLayer()->setTeamSpot(true);
	}
}

void CMClient::doRefuseTeamMsg(RefuseTeam_Msg* msg)
{
	std::string name = findRoleNameByFd(msg->fd);
	TipLayer* tiplayer = TipLayer::createTipLayer(name + StringValue("RefuseText"));
	if (GetIntData("IsHaveGameScene") == 1)
	{
		CurGameScene()->addChild(tiplayer);
	}
}

void CMClient::doAgreeTeamMsg(AgreeTeam_Msg* msg)
{
	std::string name = findRoleNameByFd(msg->fd);
	TipLayer* tiplayer = TipLayer::createTipLayer(name + StringValue("AgreeText"));
	if (GetIntData("IsHaveGameScene") == 1)
	{
		CurGameScene()->addChild(tiplayer);
	}
	CameraPlayer::getPlayerInstance()->setTeamStatus(P_STATUS_HEADER);
	TeamManager::getInstance()->createTeam(msg->fd, P_STATUS_MEMBER);
}

void CMClient::sendTeamMoveMsg(cocos2d::Vec2 target, int dest)
{
	TeamMove_Msg msg;
	msg.x = target.x;
	msg.y = target.y;
	msg.dest = dest;
	SendMsg((char*)&msg, sizeof(msg));
}

void CMClient::doTeamMoveMsg(TeamMove_Msg* msg)
{
	CameraPlayer::getPlayerInstance()->moveTo(Vec2{ msg->x,msg->y }, 1);
}

void CMClient::sendTeamGotoMapMsg(std::string map, cocos2d::Vec2 target, int dest)
{
	TeamGotoMap_Msg msg;
	msg.dest = dest;
	strcpy_s(msg.map, map.c_str());
	msg.x = target.x;
	msg.y = target.y;
	SendMsg((char*)&msg, sizeof(msg));
}

void CMClient::doTeamGotoMapMsg(TeamGotoMap_Msg* msg)
{
	if (CCDirector::getInstance()->getRunningScene()->getName() == "GameScene")
		m_gotoMapMsgs.push_back(*msg);
}

void CMClient::SendTeamDissolveMsg(int dest)
{
	TeamManage_Msg msg;
	msg.type = M_DissolveTeam;
	msg.dest = dest;
	SendMsg((char*)&msg, sizeof(msg));
}

void CMClient::doTeamDissolveMsg()
{
	TeamManager::getInstance()->dissolveTeam();
	auto tipLayer = TipLayer::createTipLayer(StringValue("TeamDissolveText"));
	if (Director::getInstance()->getRunningScene() != nullptr)
		Director::getInstance()->getRunningScene()->addChild(tipLayer);
}

void CMClient::sendTeamFightMsg(int dest, std::string name, int nums)
{
	TeamFight_Msg msg;
	msg.dest = dest;
	strcpy_s(msg.name, name.c_str());
	msg.nums = nums;
	SendMsg((char*)&msg, sizeof(msg));
}

void CMClient::doTeamFightMsg(TeamFight_Msg* msg)
{
	if (Director::getInstance()->getRunningScene()->getName() == "GameScene")
	{
		Director::getInstance()->pause();
		SetFloatData("DestX", PlayerPos.x);
		SetFloatData("DestY", PlayerPos.y);
		SetIntData("IsHaveGameScene", 0);
		auto fightScene = FightLayer::createFightScene(msg->name, msg->nums);
		Director::getInstance()->resume();
		auto reScene = TransitionFadeUp::create(0.5, fightScene);
		Director::getInstance()->replaceScene(reScene);
	}
}
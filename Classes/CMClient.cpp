#include"CMClient.h"
#include"GameData.h"
#include"Commen.h"
#include"GameDynamicData.h"
#include"CameraPlayer.h"
#include"GameScene.h"
#include"ObjectLayer.h"
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
		Player_Info pinfo;
		InitData_Msg* rlmsg = (InitData_Msg*)buff;	
		pinfo.playername = rlmsg->playername;
		pinfo.attack = rlmsg->attack;
		pinfo.blood = rlmsg->blood;
		pinfo.curmap = rlmsg->curmap;
		pinfo.defense = rlmsg->defense;
		pinfo.mana = rlmsg->mana;
		pinfo.playertype = rlmsg->playertype;
		pinfo.rolename = rlmsg->rolename;
		pinfo.fd = rlmsg->fd;
		pinfo.grade = rlmsg->grade;
		m_playerlist.push_back(pinfo);
	}
		break;
	case M_WorldTalk:
	{
		WorldTalk_Msg* rlmsg = (WorldTalk_Msg*)buff;
		m_worldTalkMsgs.push_back(rlmsg->msg);
	}
		break;
	case M_PrivateTalk:
	{
		PrivateTalk_Msg* rlmsg = (PrivateTalk_Msg*)buff;
		PrivateMsg pmsg;
		pmsg.dest = rlmsg->dest;
		pmsg.msg = rlmsg->msg;
		m_privateTalkMsgs.push_back(pmsg);
	}
		break;
	case M_InitPos:
	{
		doInitPlayerPosMsg((InitPos_Msg*)buff);
	}
		break;
	case M_PlayerLeave:
	{
		PlayerLeave_Msg* rlmsg = (PlayerLeave_Msg*)buff;
		removePlayer(rlmsg->fd);
	}
		break;
	case M_MoveTo:
	{
		doPlayerMoveToMsg((MoveTo_Msg*)buff);
	}
		break;
	case M_VerifyPos:
	{
		doPlayerPosVerifyMsg((VerifyPos_Msg*)buff);
	}
		break;
	case M_UpdateData:
	{
		doPlayerDataUpdaeMsg((UpdateData_Msg*)buff);
	}
		break;
	case M_UpdateMap:
	{
		doUpdatePlayerMapMsg((UpdateMap_Msg*)buff);
	}
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
	SendMsg((char*)&msg, sizeof(msg));
}

void CMClient::doInitPlayerPosMsg(InitPos_Msg* msg)
{
	for (auto& var : m_playerlist)
	{
		if (msg->fd == var.fd)
		{
			var.x = msg->x;
			var.y = msg->y;
			CurGameScene()->getObjectLayer()->addPlayer(var);
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

void CMClient::removePlayer(int fd)
{
	for (auto it = m_playerlist.begin(); it != m_playerlist.end(); ++it)
	{
		if (it->fd == fd)
		{
			CurGameScene()->getObjectLayer()->removePlayer(it->playername, it->rolename);
			m_playerlist.erase(it);
			return;
		}
	}
}

void CMClient::SendMoveToMsg(const cocos2d::Vec2& pos)
{
	MoveTo_Msg msg;
	msg.type = M_MoveTo;
	msg.fd = -1;
	msg.x = pos.x;
	msg.y = pos.y;
	SendMsg((char*)&msg, sizeof(msg));
}

void CMClient::doPlayerMoveToMsg(MoveTo_Msg* msg)
{
	Vec2 target{ msg->x,msg->y };
	for (auto var : m_playerlist)
	{
		if (var.fd == msg->fd)
		{
			CurGameScene()->getObjectLayer()->moveOtherPlayer(var.playername, var.rolename, target);
		}
	}
}

void CMClient::doPlayerPosVerifyMsg(VerifyPos_Msg* msg)
{
	for (auto& var : m_playerlist)
	{
		if (var.fd == msg->fd)
		{
			var.x = msg->x;
			var.y = msg->y;
			CurGameScene()->getObjectLayer()->verifyPlayerPos(var.playername, var.rolename, Vec2{ msg->x,msg->y });
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
	for (auto& var : m_playerlist)
	{
		if (var.fd == msg->fd)
		{
			var.attack = msg->attack;
			var.defense = msg->defense;
			var.blood = msg->blood;
		 	var.grade=msg->grade;
			var.mana = msg->mana;
			CurGameScene()->getObjectLayer()->updatePlayerData(var.playername, var.rolename, *msg);
		}
	}
}

void CMClient::updatePlayerMap()
{
	UpdateMap_Msg msg;
	msg.type = M_UpdateMap;
	msg.fd = -1;
	msg.curmap = GetIntData("CurMap");
	SendMsg((char*)&msg, sizeof(msg));
}

void CMClient::doUpdatePlayerMapMsg(UpdateMap_Msg* msg)
{
	for (auto& var : m_playerlist)
	{
		if (var.fd == msg->fd)
		{
			var.curmap = msg->curmap;
		}
	}
}

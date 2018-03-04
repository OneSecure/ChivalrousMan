#include"CMClient.h"
#include"GameData.h"
#include"Commen.h"
#include"GameDynamicData.h"
#include"CameraPlayer.h"
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
	M_Type type = *((M_Type*)buff);
	switch (type)
	{
	case M_WorldTalk:
		
		break;
	case M_PrivateTalk:
		
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

void CMClient::SendEntryMsg()
{
	EntryGame_Msg msg;
	msg.type = M_EntryGame;
	strcpy_s(msg.playername, GetStringData("playername").c_str());
	strcpy_s(msg.rolename, GetStringData("rolename").c_str());
	SendMsg((char*)(&msg), sizeof(msg));
}

void CMClient::SendPlayerData()
{
	InitData_Msg msg;
	msg.type = M_InitData;
	msg.attack = GetPlayerData().getattack();
	msg.blood = GetPlayerData().getblood();
	msg.defense = GetPlayerData().getdefense();
	msg.mana = GetPlayerData().getmana();
	SendMsg((char*)&msg, sizeof(msg));
}
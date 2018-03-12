#pragma once
#ifndef SHAREDATA_H
#define SHAREDATA_H
#include<string>

enum M_Type
{
	M_EntryGame,   //
	M_InitData,      //初始化玩家数据
	M_WorldTalk,     //世界聊天消息
	M_PrivateTalk,    //私聊消息
	M_InitPos,      //初始化位置
	M_PlayerLeave,   //玩家离线
	M_MoveTo,    //玩家移动到某处
	M_VerifyPos,   //校验玩家位置
	M_UpdateData,   //更新玩家信息
	M_TeamApply,   //队伍申请消息
	M_RefuseTeam,    //拒绝组队申请
	M_AgreeTeam,     //同意组队
	M_TeamMove,      //队伍移动
	M_TeamGotoMap,   //队伍切换地图·
	M_DissolveTeam,   //解散队伍
	M_QuitTeam,         //退出队伍
	M_KickOutteam,    //踢出队伍
	M_TeamFight,   //队伍进入战斗
}; 

struct Player_Info
{
	std::string playername;
	std::string rolename;
	float blood;
	float mana;
	float attack;
	float defense;
	int curmap;
	std::string playertype;
	float x;
	float y;
	int grade;
	int fd;
};

struct InitData_Msg
{
	M_Type type;
	char playername[40];
	char rolename[40];
	float blood;
	float mana;
	float attack;
	float defense;
	int curmap;
	char playertype[10];
	int grade;
	int fd;
};

struct WorldTalk_Msg
{
	M_Type type;
	int fd;
	char msg[200];
};

struct PrivateTalk_Msg
{
	M_Type type;
	int fd;
	int dest;
	char msg[200];
};

struct InitPos_Msg
{
	M_Type type;
	float x;
	float y;
	int fd;
	int curmap;
};

struct PlayerLeave_Msg
{
	M_Type type;
	int fd;
};

struct MoveTo_Msg
{
	M_Type type;
	float x;
	float y;
	int fd;
	int less;

	MoveTo_Msg()
	{
		less = 0;
	}
};

struct  VerifyPos_Msg
{
	M_Type type;
	float x;
	float y;
	int fd;
};

struct UpdateData_Msg
{
	M_Type type;
	float blood;
	float mana;
	float attack;
	float defense;
	int grade;
	int fd;
};

struct TeamApply_Msg
{
	M_Type type;
	int fd;
	int dest;
	
	TeamApply_Msg()
	{
		fd = -1;
		type = M_TeamApply;
	}
};

struct RefuseTeam_Msg
{
	M_Type type;
	int fd;
	int dest;

	RefuseTeam_Msg()
	{
		fd = -1;
		type = M_RefuseTeam;
	}
};

struct AgreeTeam_Msg
{
	M_Type type;
	int fd;
	int dest;
	
	AgreeTeam_Msg()
	{
		type = M_AgreeTeam;
		fd = -1;
	}
};

struct TeamMove_Msg
{
	M_Type type;
	float x;
	float y;
	int fd;
	int dest;

	TeamMove_Msg()
	{
		type = M_TeamMove;
		fd = -1;
		dest = -1;
	}
};

struct TeamGotoMap_Msg
{
	M_Type type;
	char map[10];
	float x;
	float y;
	int dest;
	
	TeamGotoMap_Msg()
	{
		type = M_TeamGotoMap;
	}
};

struct TeamManage_Msg
{
	M_Type type;
	int fd;
	int dest;
};

struct TeamFight_Msg
{
	M_Type type;
	char name[20];
	int fd;
	int dest;
	int nums;

	TeamFight_Msg()
	{
		type = M_TeamFight;
		fd = -1;
	}
};

#endif // SHAREDATA_H
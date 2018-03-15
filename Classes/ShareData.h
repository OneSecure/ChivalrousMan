#pragma once
#ifndef SHAREDATA_H
#define SHAREDATA_H
#include<string>

enum M_Type
{
	M_EntryGame,   //
	M_InitData,      //��ʼ���������
	M_WorldTalk,     //����������Ϣ
	M_PrivateTalk,    //˽����Ϣ
	M_InitPos,      //��ʼ��λ��
	M_PlayerLeave,   //�������
	M_MoveTo,    //����ƶ���ĳ��
	M_VerifyPos,   //У�����λ��
	M_UpdateData,   //���������Ϣ
	M_TeamApply,   //����������Ϣ
	M_RefuseTeam,    //�ܾ��������
	M_AgreeTeam,     //ͬ�����
	M_TeamMove,      //�����ƶ�
	M_TeamGotoMap,   //�����л���ͼ��
	M_DissolveTeam,   //��ɢ����
	M_QuitTeam,         //�˳�����
	M_KickOutteam,    //�߳�����
	M_TeamFight,       //�������ս��
	M_MonsterAtk,     //���������Ϣ
	M_PlayerAtk,           //��ҽ�����Ϣ
	M_PlayerRun,           //���������Ϣ
	M_UseMedication,   //ʹ��ҩƷ��Ϣ
	M_PlayerDie,           //���������Ϣ
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

struct MonsterAtk_Msg
{
	M_Type type;
	int fd;
	int dest;        //���͸�˭
	int who;        //˭����
	int towho;     //����˭

	MonsterAtk_Msg()
	{
		type = M_MonsterAtk;
	}
};

struct PlayerAtk_Msg
{
	M_Type type;
	char skill[30];   //�Ƿ�ʹ�ü���
	int grade;
	int fd;               //
	int dest;           //���͸�˭
	int towho;        //����˭

	PlayerAtk_Msg()
	{
		type = M_PlayerAtk;
	}
};

struct PlayerRun_Msg
{
	M_Type type;
	int fd;
	int dest;
	int flag;
	
	PlayerRun_Msg()
	{
		type = M_PlayerRun;
		fd = -1;
		dest = -1;
	}
};

struct UseMedication_Msg
{
	M_Type type;
	int fd;
	int dest;

	UseMedication_Msg()
	{
		type = M_UseMedication;
	}
};

struct PlayerDie_Msg
{
	M_Type type;
	int fd;
	int dest;

	PlayerDie_Msg()
	{
		type = M_PlayerDie;
	}
};

#endif // SHAREDATA_H
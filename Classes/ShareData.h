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
	M_UpdateMap,
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
	char msg[200];
};

struct PrivateTalk_Msg
{
	M_Type type;
	int dest;
	char msg[200];
};

struct InitPos_Msg
{
	M_Type type;
	float x;
	float y;
	int fd;
};

struct PlayerLeave_Msg
{
	M_Type type;
	int fd;
};

struct PrivateMsg
{
	int dest;
	std::string msg;
};

struct MoveTo_Msg
{
	M_Type type;
	float x;
	float y;
	int fd;
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

struct UpdateMap_Msg
{
	M_Type type;
	int fd;
	int curmap;
};

#endif // SHAREDATA_H
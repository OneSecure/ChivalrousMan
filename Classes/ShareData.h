#pragma once
#ifndef SHAREDATA_H
#define SHAREDATA_H
#include<string>

enum M_Type
{
	M_EntryGame,
	M_InitData,
	M_WorldTalk,
	M_PrivateTalk,
};

struct Player_Info
{
	std::string playername;
	std::string rolename;
	float blood;
	float mana;
	float attack;
	float defense;
};

struct EntryGame_Msg
{
	M_Type type;
	char playername[40];
	char rolename[40];
};

struct InitData_Msg
{
	M_Type type;
	float blood;
	float mana;
	float attack;
	float defense;
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


#endif // SHAREDATA_H


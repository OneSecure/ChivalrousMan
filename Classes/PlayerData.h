#pragma once
#ifndef __PLAYER_DATA_H__
#define __PLAYER_DATA_H__
#include"PreProcess.h"



/*
*保存玩家数据
*/
class PlayerData
{
public:
	PlayerData();
	~PlayerData();

	PROPERTY__REF(float, m_glod, glod)
	PROPERTY__REF(float, m_grade, grade)
	PROPERTY__REF(float, m_blood, blood)
	PROPERTY__REF(float, m_mana, mana)
	PROPERTY__REF(float, m_attack, attack)
	PROPERTY__REF(float, m_defense, defense)
	PROPERTY__REF(float, m_speed, speed)
	PROPERTY__REF(float,m_exp,exp)
	PROPERTY__REF(float,m_maxExp,maxExp)
};

#endif // !__PLAYER_DATA_H__


#pragma once
#ifndef __PLAYER_DATA_H__
#define __PLAYER_DATA_H__
#include"PreProcess.h"



/*
*�����������
*/
class PlayerData
{
public:
	PlayerData();
	~PlayerData();

	/*
	*���ӽ��
	*/
	void addGlod(const float& vl);

	/*
	*���ٽ��
	*/
	float subGlod(const float& vl);

	/*
	*���Ӿ���
	*/
	void addExp(const float& vl);

	/*
	*���ӵ�ǰѪ��
	*/
	void addcurBlood(const float& vl);

	/*
	*���ٵ�ǰ��Ѫ��
	*/
	void subcurBlood(const float& vl);

	/*
	*���ӵ�ǰ��ħ��
	*/
	void addcurMana(const float& vl);

	/*
	*���ٵ�ǰ��ħ��
	*/
	void subcurMana(const float& vl);

	/*
	*����
	*/
	void upGrade();

	//������������
	void addProperty(float blood, float mana, float attack, float defense);

	PROPERTY__REF(float, m_glod, glod)
	PROPERTY__REF(float, m_grade, grade)
	PROPERTY__REF(float, m_blood, blood)
	PROPERTY__REF(float, m_mana, mana)
	PROPERTY__REF(float, m_attack, attack)
	PROPERTY__REF(float, m_defense, defense)
	PROPERTY__REF(float, m_speed, speed)
	PROPERTY__REF(float,m_exp,exp)
	PROPERTY__REF(float,m_maxExp,maxExp)
	PROPERTY__REF(float,m_curblood,curblood)
	PROPERTY__REF(float,m_curmana,curmana)
};

#endif // !__PLAYER_DATA_H__


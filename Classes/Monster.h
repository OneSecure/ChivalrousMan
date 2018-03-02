#pragma once
#ifndef __MONSTER_H__
#define __MONSTER_H__
#include"PreProcess.h"
#include<string>

/*
*class Monster
*�������
*/
class Monster Inherit(cocos2d::Sprite) 
{
public:
	Monster(const std::string& name);
	virtual ~Monster();

	/*
	*�������ƴ�������
	*@param name��������
	*/
	static Monster* createWithName(const std::string& name);

	bool init(const std::string& name);

	/*
	*void beAttack(float attack)
	*������
	*@param attack���������˺�
	*@return int:����-1��ʾ����������0��ʾ��û��
	*/
	int beAttack(float attack);

	PROPERTY__REF(float, m_attack, attack)
	PROPERTY__REF(float, m_blood, blood)
	PROPERTY__REF(float, m_defense, defense)
	PROPERTY__REF(float, m_speed, speed)
	PROPERTY__REF(std::string, m_name, name)
	PROPERTY__REF(float, m_exp, exp)    //ɱ������þ���ֵ
	PROPERTY__REF(float, m_glod, glod)     //ɱ������ý����
	PROPERTY__REF(float, m_frames, frames)

	bool isDie();
private:
	/*
	*initProperty(const std::string name)
	*�������Ƴ�ʼ����������ֵ
	*@param name:��������
	*/
	void initProperty(const std::string& name);

	/*
	*initFaceWithFrames(int num);
	*���ݹ������ƺͶ���֡����ʼ������Ķ���
	*@param name ����������
	*@param num��֡��
	*/
	void initMonsterAnimation(const std::string& name, int num);

	bool m_isdie = false;
};

#endif // !__MONSTER_H__


#pragma once
#ifndef __MONSTER_H__
#define __MONSTER_H__
#include"PreProcess.h"
#include"Animal.h"

/*
*class Monster
*�������
*/
class Monster Inherit(Animal) 
{
public:
	Monster(const std::string name);
	virtual ~Monster();

	PROPERTY__REF(float, m_attack, attack)
	PROPERTY__REF(float, m_blood, blood)
	PROPERTY__REF(float,m_defense,defense)
	PROPERTY__REF(float, m_speed, speed)
	PROPERTY__REF(float, m_name, name)
	GettingAndSetting(cocos2d::Sprite*, m_face, face)

private:
	/*
	*initProperty(const std::string name)
	*�������Ƴ�ʼ����������ֵ
	*@param name:��������
	*/
	void initProperty(const std::string& name);

	/*
	*initFaceWithFrames(int num);
	*���ݹ������ƺͶ���֡����ʼ�������UI
	*@param name ����������
	*@param num��֡��
	*/
	void initFaceWithFrames(const std::string& name, int num);
};

#endif // !__MONSTER_H__


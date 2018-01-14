#pragma once
#ifndef __MONSTER_H__
#define __MONSTER_H__
#include"PreProcess.h"
#include<string>

/*
*class Monster
*怪物基类
*/
class Monster Inherit(cocos2d::Sprite) 
{
public:
	Monster(const std::string& name);
	virtual ~Monster();

	/*
	*根据名称创建怪物
	*@param name：怪物名
	*/
	static Monster* createWithName(const std::string& name);

	bool init(const std::string& name);

	PROPERTY__REF(float, m_attack, attack)
	PROPERTY__REF(float, m_blood, blood)
	PROPERTY__REF(float, m_defense, defense)
	PROPERTY__REF(float, m_speed, speed)
	PROPERTY__REF(std::string, m_name, name)
	PROPERTY__REF(float, m_frames, frames)
private:
	/*
	*initProperty(const std::string name)
	*根据名称初始化怪物属性值
	*@param name:怪物名称
	*/
	void initProperty(const std::string& name);

	/*
	*initFaceWithFrames(int num);
	*根据怪物名称和动画帧数初始化怪物的动画
	*@param name ：怪物名称
	*@param num：帧数
	*/
	void initMonsterAnimation(const std::string& name, int num);
};

#endif // !__MONSTER_H__


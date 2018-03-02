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

	/*
	*void beAttack(float attack)
	*被攻击
	*@param attack：攻击的伤害
	*@return int:返回-1表示死亡，返回0表示还没死
	*/
	int beAttack(float attack);

	PROPERTY__REF(float, m_attack, attack)
	PROPERTY__REF(float, m_blood, blood)
	PROPERTY__REF(float, m_defense, defense)
	PROPERTY__REF(float, m_speed, speed)
	PROPERTY__REF(std::string, m_name, name)
	PROPERTY__REF(float, m_exp, exp)    //杀死它获得经验值
	PROPERTY__REF(float, m_glod, glod)     //杀死它获得金币数
	PROPERTY__REF(float, m_frames, frames)

	bool isDie();
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

	bool m_isdie = false;
};

#endif // !__MONSTER_H__


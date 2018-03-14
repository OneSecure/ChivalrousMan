#pragma once
#ifndef  __SKILL_H__
#define  __SKILL_H__
#include"Thing.h"

/*
*class Skill
*技能图标
*/
class Skill Inherit(Thing)
{
public:
	static Skill* createWithImage(const std::string& filename);
	
	bool init(const std::string& filename);

	/*
	*使用技能
	*@param obj:技能显示的地方
	*@param who:谁释放技能
	*/
	virtual float beUse(cocos2d::CCObject* obj, cocos2d::CCObject* who,cocos2d::CCObject* towho) override;
	Skill(const std::string& name);
	virtual ~Skill();

	/*
	*提升等级
	*/
	void incGrade();

	/*
	*获取使用这个技能消耗的魔法
	*/
	float getUseMana();
private: 
	void initProperty(const std::string& name);
	
	PROPERTY__REF(float, m_baseAttack, baseAttack)
	PROPERTY__REF(float,m_baseMana,baseMana)
	PROPERTY__REF(int, m_baseupGlod, baseupGlod)
	PROPERTY__REF(int, m_grade, grade)
};

#endif // ! __SKILL_H__
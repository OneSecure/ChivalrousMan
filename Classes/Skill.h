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

	virtual float beUse(cocos2d::CCObject* obj) override;
	Skill(const std::string& name);
	virtual ~Skill();

	/*
	*提升等级
	*/
	void incGrade();
private: 
	void initProperty(const std::string& name);
	
	PROPERTY__REF(std::string, m_name, name)
	PROPERTY__REF(float, m_baseAttack, baseAttack)
	PROPERTY__REF(float,m_baseMana,baseMana)
	PROPERTY__REF(int, m_baseupGlod, baseupGlod)
	PROPERTY__REF(int, m_grade, grade)
};

#endif // ! __SKILL_H__
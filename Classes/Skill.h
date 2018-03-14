#pragma once
#ifndef  __SKILL_H__
#define  __SKILL_H__
#include"Thing.h"

/*
*class Skill
*����ͼ��
*/
class Skill Inherit(Thing)
{
public:
	static Skill* createWithImage(const std::string& filename);
	
	bool init(const std::string& filename);

	/*
	*ʹ�ü���
	*@param obj:������ʾ�ĵط�
	*@param who:˭�ͷż���
	*/
	virtual float beUse(cocos2d::CCObject* obj, cocos2d::CCObject* who,cocos2d::CCObject* towho) override;
	Skill(const std::string& name);
	virtual ~Skill();

	/*
	*�����ȼ�
	*/
	void incGrade();

	/*
	*��ȡʹ������������ĵ�ħ��
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
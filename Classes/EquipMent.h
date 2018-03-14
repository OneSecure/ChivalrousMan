#pragma once
#ifndef __EQUIP_MENT_H__
#define __EQUIP_MENT_H__
#include"Thing.h"

/*
*class EquipMent
*װ��
*/
class EquipMent Inherit(Thing)
{
public:
	static EquipMent* createWithImage(const std::string& filename);

	bool init(const std::string& filename);

	EquipMent(const std::string& name);
	virtual ~EquipMent();

	virtual float beUse(cocos2d::CCObject* obj,cocos2d::CCObject* who=nullptr,cocos2d::CCObject* towho=nullptr) override;

	/*
	*��жװ��
	*/
	int Disassemble(cocos2d::Node* node);

	/*
	*upgrade();
	*װ������
	*/
	void upgrade(cocos2d::Node* node);
	
	/*
	*showProperty(cocos2d::Node* obj);
	*��ʾװ������
	*@param node����ʾ�Ľڵ�
	*/
	void showProperty(cocos2d::Node* node);

	/*
	*����Ƿ��������
	*/
	float upGlod();
protected:
	/*
	*initProperty(const std::string& name);
	*��ʼ������ֵ
	*@param name:��Ʒ��
	*/
	void initProperty(const std::string& name);

	//���ӵ�Ѫ��ֵ
	PROPERTY__REF(float, m_addblood, addblood)
		//���ӵ�ħ��ֵ
		PROPERTY__REF(float, m_addmana, addmana)
		//���ӵĹ�����
		PROPERTY__REF(float, m_addattack, addattack)
		//���ӵķ�����
		PROPERTY__REF(float, m_adddefense, adddefense)
		//�����ٶ�
		PROPERTY__REF(float, m_addspeed, speed)
		//װ���ȼ�
		PROPERTY__REF(float, m_grade, grade)
		//װ������
		PROPERTY__REF(int, m_type, type)
		//�������������Ǯ
		PROPERTY__REF(float, m_baseupglod, baseupglod)
};

#endif // !__EQUIP_MENT_H__


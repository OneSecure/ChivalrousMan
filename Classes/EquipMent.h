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
};

#endif // !__EQUIP_MENT_H__


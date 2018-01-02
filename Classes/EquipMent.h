#pragma once
#ifndef __EQUIP_MENT_H__
#define __EQUIP_MENT_H__
#include"Thing.h"

/*
*class EquipMent
*装备
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
	*初始化属性值
	*@param name:物品名
	*/
	void initProperty(const std::string& name);

	//增加的血量值
	PROPERTY__REF(float, m_addblood, addblood)
	//增加的魔量值
	PROPERTY__REF(float, m_addmana, addmana)
	//增加的攻击力
	PROPERTY__REF(float, m_addattack, addattack)
	//增加的防御力
	PROPERTY__REF(float, m_adddefense, adddefense)
	//增加速度
	PROPERTY__REF(float, m_addspeed, speed)
};

#endif // !__EQUIP_MENT_H__


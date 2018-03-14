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

	virtual float beUse(cocos2d::CCObject* obj,cocos2d::CCObject* who=nullptr,cocos2d::CCObject* towho=nullptr) override;

	/*
	*拆卸装备
	*/
	int Disassemble(cocos2d::Node* node);

	/*
	*upgrade();
	*装备升级
	*/
	void upgrade(cocos2d::Node* node);
	
	/*
	*showProperty(cocos2d::Node* obj);
	*显示装备属性
	*@param node：显示的节点
	*/
	void showProperty(cocos2d::Node* node);

	/*
	*检查是否可以升级
	*/
	float upGlod();
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
		//装备等级
		PROPERTY__REF(float, m_grade, grade)
		//装备类型
		PROPERTY__REF(int, m_type, type)
		//基础升级所需金钱
		PROPERTY__REF(float, m_baseupglod, baseupglod)
};

#endif // !__EQUIP_MENT_H__


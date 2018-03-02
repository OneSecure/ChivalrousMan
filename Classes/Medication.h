#pragma once
#ifndef __MEDICATION_H__
#define __MEDICATION_H__
#include"Thing.h"

/*
*class Medication
*药品
*/
class Medication Inherit(Thing)
{
public:
	static Medication* createWithImage(const std::string& filename);

	bool init(const std::string& filename);

	virtual float beUse(cocos2d::CCObject* obj) override;

	Medication(const std::string& name);
 	virtual ~Medication();
private:
	/*
	*initProperty(const std::string& name);
	*初始化属性值
	*@param name:物品名
	*/
     void initProperty(const std::string& name);

	 PROPERTY__REF(float, m_addblood, addblood)
	 PROPERTY__REF(float, m_addmana, addmana)
};

#endif // !__MEDICATION_H__


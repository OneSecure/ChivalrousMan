#pragma once
#ifndef __MEDICATION_H__
#define __MEDICATION_H__
#include"Thing.h"

/*
*class Medication
*ҩƷ
*/
class Medication Inherit(Thing)
{
public:
	static Medication* createWithImage(const std::string& filename);

	bool init(const std::string& filename);

	Medication(const std::string& name);
 	virtual ~Medication();
private:
	/*
	*initProperty(const std::string& name);
	*初始化属性值
	*@param name:物品名
	*/
     void initProperty(const std::string& name);
};

#endif // !__MEDICATION_H__


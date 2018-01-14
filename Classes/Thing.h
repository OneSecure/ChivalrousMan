#pragma once
#ifndef __THING_H__
#define __THING_H__
#include"PreProcess.h"
#include<vector>
#include<string>

/*
*物品基类
*class Thing
*/
class Thing Inherit(cocos2d::MenuItemImage)
{
public:
	Thing(const std::string &name);
	virtual ~Thing();

	/*
	*showDetail();
	*显示物品详情
	*/
	virtual void showDetail(cocos2d::Node* node);

	virtual std::vector<std::string>& getDetails();

	static std::string getName(const std::string& name);
protected:
	/*
	*initDetails(const std::string& name)
	*初始化细节描述
	*@param name：物品名
	*/
	virtual void initDetails(const std::string& name);

	//细节描述
	std::vector<std::string> m_details;
	 //购买价格
	PROPERTY__REF(float, m_buyglod, buyglod)
	//卖出价格
	PROPERTY__REF(float, m_sellglod, sellglod)
	//名称
	PROPERTY__REF(std::string,m_name,name)
};

#endif // !__THING_H__


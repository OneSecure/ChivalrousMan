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
	/*
	*createWithImage(const std::string& filename)
	*通过文件名创建一个背包物体
	*@param filename:文件名
	*/
	static Thing* createWithImage(const std::string& filename);

	Thing();
	virtual ~Thing();

	virtual bool init(const std::string& filename);

	/*
	*showDetail();
	*显示物品详情
	*/
	virtual void showDetail();
private:
	std::vector<std::string> m_details;
};

#endif // !__THING_H__


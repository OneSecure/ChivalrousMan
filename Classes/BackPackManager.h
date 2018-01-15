#pragma once
#ifndef __BACKPACK_MANAGER_H__
#define __BACKPACK_MANAGER_H__
#include"PreProcess.h"
#include<thread>
#include<atomic>
#include<mutex>
#include<string>
#include<list>

struct ThingInfo
{
	std::string name;
	int type;
	int nums;

	bool operator==(const ThingInfo& info)
	{
		return (name == info.name&&type == info.type);
	}
};

#define AddToBackPack BackPackManager::getInstance()->addBackPackThing
#define RemoveFromBackPack BackPackManager::getInstance()->removeBackPackThing
#define BackPackMap BackPackManager::getInstance()->getBackPackMap

/*
*class BackPackManager
*背包管理器
*/
class BackPackManager
{
	GET_SINGLE_OBJECT(BackPackManager)
public:
	static void release();

	/*
	*addBackPackThing();
	*添加背包物品
	*/
	void addBackPackThing(ThingInfo thinginfo);

	/*
	*移除背包物品
	*removeBackPackThing();
	*@param name：物品名称
	*@return int：
	*/
	int removeBackPackThing(const std::string& name);

	/*
	*getBackPackList()
	*获取背包物品内容
	*/
	const std::list<ThingInfo>& getBackPackMap();
private:
	BackPackManager();
	~BackPackManager();
	
	std::list<ThingInfo> m_backpackList;
	SINGLE_ATTRIBUTES(BackPackManager);
};
#endif // !__BACKPACK_MANAGER_H__


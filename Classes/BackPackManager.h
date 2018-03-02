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
	std::string name = "";
	int type = NULL;
	int nums = 0;
	int grade = 1;

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
	*@return int：返回0表示没找到该物品，返回-1表示该物品减少一个，返回-2表示该物品减少到0
	*/
	int removeBackPackThing(const std::string& name);

	/*
	*getBackPackList()
	*获取背包物品内容
	*/
	const std::list<ThingInfo>& getBackPackMap();

	/*
	*int ThingNums(const std::string& name);
	*获取某物品数量
	*@param name ：物品名称1
	*@return int ：
	*/
	int ThingNums(const std::string& name);

	/*
	*readBackpackInfo();
	*读取角色背包信息
	*/
	void readBackpackInfo();

	void saveBackpackInfo();
private:
	void updateBackpack(ThingInfo info);

	void deleteBackpack(ThingInfo info);

	BackPackManager();
	~BackPackManager();
	
	std::list<ThingInfo> m_backpackList;
	SINGLE_ATTRIBUTES(BackPackManager);
};
#endif // !__BACKPACK_MANAGER_H__


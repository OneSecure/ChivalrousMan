#pragma once
#ifndef __BACKPACK_MANAGER_H__
#define __BACKPACK_MANAGER_H__
#include"PreProcess.h"
#include<thread>
#include<atomic>
#include<mutex>
#include<string>
#include<map>

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
	void addBackPackThing(const std::string& name,const int& type);

	/*
	*移除背包物品
	*removeBackPackThing();
	*/
	void removeBackPackThing(const std::string& name);

	/*
	*getBackPackList()
	*获取背包物品内容
	*/
	const std::map<std::string, int>& getBackPackMap();
private:
	BackPackManager();
	~BackPackManager();
	
	std::map<std::string, int> m_backpackMap;
	SINGLE_ATTRIBUTES(BackPackManager);
};
#endif // !__BACKPACK_MANAGER_H__


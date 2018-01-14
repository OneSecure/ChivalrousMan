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
*����������
*/
class BackPackManager
{
	GET_SINGLE_OBJECT(BackPackManager)
public:
	static void release();

	/*
	*addBackPackThing();
	*��ӱ�����Ʒ
	*/
	void addBackPackThing(const std::string& name,const int& type);

	/*
	*�Ƴ�������Ʒ
	*removeBackPackThing();
	*/
	void removeBackPackThing(const std::string& name);

	/*
	*getBackPackList()
	*��ȡ������Ʒ����
	*/
	const std::map<std::string, int>& getBackPackMap();
private:
	BackPackManager();
	~BackPackManager();
	
	std::map<std::string, int> m_backpackMap;
	SINGLE_ATTRIBUTES(BackPackManager);
};
#endif // !__BACKPACK_MANAGER_H__


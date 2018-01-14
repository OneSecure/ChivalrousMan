#pragma once
#ifndef __BACKPACK_MANAGER_H__
#define __BACKPACK_MANAGER_H__
#include"PreProcess.h"
#include<thread>
#include<atomic>
#include<mutex>

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
	void addBackPackThing();

	/*
	*移除背包物品
	*removeBackPackThing();
	*/
	void removeBackPackThing();
private:
	BackPackManager();
	~BackPackManager();

	SINGLE_ATTRIBUTES(BackPackManager);
};
#endif // !__BACKPACK_MANAGER_H__


#pragma once
#ifndef __BACKPACK_MANAGER_H__
#define __BACKPACK_MANAGER_H__
#include"PreProcess.h"
#include<thread>
#include<atomic>
#include<mutex>

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
	void addBackPackThing();

	/*
	*�Ƴ�������Ʒ
	*removeBackPackThing();
	*/
	void removeBackPackThing();
private:
	BackPackManager();
	~BackPackManager();

	SINGLE_ATTRIBUTES(BackPackManager);
};
#endif // !__BACKPACK_MANAGER_H__


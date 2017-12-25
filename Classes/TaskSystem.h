#pragma once
#ifndef __TASK_SYSTEM_H__
#define __TASK_SYSTEM_H__
#include"PreProcess.h"
#include<atomic>
#include<mutex>

/*
*TaskSystem
*任务系统
*/
class TaskSystem
{
	GET_SINGLE_OBJECT(TaskSystem);
private:
	TaskSystem();
	~TaskSystem();

	SINGLE_ATTRIBUTES(TaskSystem);
};

#endif // !__TASK_SYSTEM_H__


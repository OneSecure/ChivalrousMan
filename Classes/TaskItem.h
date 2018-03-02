#pragma once
#ifndef __TASK_ITEM_H__
#define __TASK_ITEM_H__
#include"PreProcess.h"
#include"TaskSystem.h"

class TaskItem Inherit(cocos2d::Node)
{
	CLASS_ESSENTAIL(TaskItem)
public:
	static TaskItem*  create(const TaskInfo& tinfo);

	bool init(const TaskInfo& tinfo);
private:

};


#endif // !__TASK_ITEM_H__


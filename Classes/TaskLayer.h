#pragma once
#ifndef __TASK_LAYER_H__
#define __TASK_LAYER_H__
#include"PreProcess.h"

/*
*class TaskLayer
*��������
*/
class TaskLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(TaskLayer)
	CREATE_FUNC(TaskLayer)
public:
	bool init() override;
private:
};

#endif // !__TASK_LAYER_H__


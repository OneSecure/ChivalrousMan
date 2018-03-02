#pragma once
#ifndef __TASK_LAYER_H__
#define __TASK_LAYER_H__
#include"PreProcess.h"

/*
*class TaskLayer
*»ŒŒÒ√Ê∞Â≤„
*/
class TaskLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(TaskLayer)
	CREATE_FUNC(TaskLayer)
public:
	bool init() override;
private:
	void initTaskItem(cocos2d::Vec2 basePos);
};

#endif // !__TASK_LAYER_H__


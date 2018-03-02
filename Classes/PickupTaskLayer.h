#pragma once
#ifndef __PICKUP_TASK_LATER_H__
#define __PICKUP_TASK_LATER_H__
#include"PreProcess.h"

class Npc;

class PickupTaskLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(PickupTaskLayer)
public:
	static PickupTaskLayer* create(Npc* npc);

	bool init(Npc* npc);
private:
	void onOkBtnClickCallback(cocos2d::CCObject* sender);

	void onCancelClickCallback(cocos2d::CCObject* sender);

	Npc* m_npc;
};

#endif // !__PICKUP_TASK_LATER_H__


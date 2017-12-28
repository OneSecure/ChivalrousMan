#pragma once
#ifndef __GAME_LOGIC_LAYER_H__
#define __GAME_LOGIC_LAYER_H__
#include"PreProcess.h"
#include<string>

class GameLogicLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(GameLogicLayer)
	CREATE_FUNC(GameLogicLayer)
public:
	virtual bool init();

	void update(float dt);
private:
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	/*
	*CheckEntryDoor();
	*检查是否进入门内，并处理相应事件
	*/
	void checkEntryDoor();

	/*
	*checkCollisionNpc();
	*检测是否碰到了Npc并处理相应的事件
	*/
	void checkCollisionNpc();

	/*
	*gotoDestMap
	*切换到目标地图
	*@param dest：目标名
	*/
	void gotoDestMap(const std::string& dest);
};

#endif // !__GAME_LOGIC_LAYER_H__


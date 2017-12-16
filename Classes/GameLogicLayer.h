#pragma once
#ifndef __GAME_LOGIC_LAYER_H__
#define __GAME_LOGIC_LAYER_H__
#include"PreProcess.h"

class GameLogicLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(GameLogicLayer)
	CREATE_FUNC(GameLogicLayer)
public:
	virtual bool init();

	void update(float dt);

private:
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
};

#endif // !__GAME_LOGIC_LAYER_H__


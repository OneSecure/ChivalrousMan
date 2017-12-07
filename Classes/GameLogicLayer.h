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

	void onTouchEnded(cocos2d::Touch *touch,cocos2d::Event *unused_event);

	void update(float dt);
};

#endif // !__GAME_LOGIC_LAYER_H__


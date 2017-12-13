#pragma once
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include"PreProcess.h"

class GameLogicLayer;
class GameMapLayer;

class GameScene Inherit(cocos2d::Scene)
{
	CLASS_ESSENTAIL(GameScene)
	CREATE_FUNC(GameScene)
public:
	virtual bool init();

private:
	GameLogicLayer* m_logicLayer;
	GameMapLayer* m_mapLayer;
};

#endif // !__GAME_SCENE_H__

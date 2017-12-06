#pragma once
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include"PreProcess.h"
#include"Player.h"

class GameScene :public cocos2d::Scene
{
	CLASS_ESSENTAIL(GameScene)
	CREATE_FUNC(GameScene)
public:
	virtual bool init();

private:
	Player* m_player;
};

#endif __GAME_SCENE_H__

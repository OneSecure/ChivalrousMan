#pragma once
#ifndef __NEW_GAME_SCENE_H__
#define __NEW_GAME_SCENE_H__
#include"PreProcess.h"

class NewGameScene :public cocos2d::Scene
{
	CLASS_ESSENTAIL(NewGameScene)
	CREATE_FUNC(NewGameScene)
public:
	virtual bool init();
};

#endif // !__NEW_GAME_SCENE_H__


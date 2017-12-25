#pragma once
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include"PreProcess.h"

class GameLogicLayer;
class GameMapLayer;

class GameScene Inherit(cocos2d::Scene)
{
	CLASS_ESSENTAIL(GameScene)
public:
	static GameScene* createWithLevel(const int& level);

	virtual bool init(const int& level);
	
	void pauseAllActions(cocos2d::Node* hoster);

	void resumeAllActions(cocos2d::Node* hoster);
private:
	GameLogicLayer* m_logicLayer;
	GameMapLayer* m_mapLayer;
};

#endif // !__GAME_SCENE_H__

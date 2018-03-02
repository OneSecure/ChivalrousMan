#pragma once
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include"PreProcess.h"

class GameLogicLayer;
class GameMapLayer;
class ObjectLayer;

/*
*class GameScene
*游戏主场景
*/
class GameScene Inherit(cocos2d::Scene)
{
	CLASS_ESSENTAIL(GameScene)
public:
	static GameScene* createWithLevel(const int& level);

	virtual bool init(const int& level);
	
	/*
	*pauseAllActions(cocos2d::Node* hoster);
	*暂停某节点当前的所有动作和事件
	*@param hoster:主节点
	*@param except：除此子节点之外
	*/
	void pauseAllActions(cocos2d::Node* hoster, cocos2d::Node* except=nullptr);

	/*
	*resumeAllActions(cocos2d::Node* hoster);
	*恢复某节点的所有事件和动作
	*@param hoster:主节点
	*/
	void resumeAllActions(cocos2d::Node* hoster);

	/*
	*获取对象层对象
	*/
	inline ObjectLayer* getObjectLayer() { return m_objectLayer; }
	
	/*
	*获取逻辑层对象
	*/
	inline GameLogicLayer* getLogicLayer() { return m_logicLayer; }
private:

	GameLogicLayer* m_logicLayer;
	GameMapLayer* m_mapLayer;
	ObjectLayer* m_objectLayer;
};

#endif // !__GAME_SCENE_H__

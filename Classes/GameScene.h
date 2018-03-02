#pragma once
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include"PreProcess.h"

class GameLogicLayer;
class GameMapLayer;
class ObjectLayer;

/*
*class GameScene
*��Ϸ������
*/
class GameScene Inherit(cocos2d::Scene)
{
	CLASS_ESSENTAIL(GameScene)
public:
	static GameScene* createWithLevel(const int& level);

	virtual bool init(const int& level);
	
	/*
	*pauseAllActions(cocos2d::Node* hoster);
	*��ͣĳ�ڵ㵱ǰ�����ж������¼�
	*@param hoster:���ڵ�
	*@param except�������ӽڵ�֮��
	*/
	void pauseAllActions(cocos2d::Node* hoster, cocos2d::Node* except=nullptr);

	/*
	*resumeAllActions(cocos2d::Node* hoster);
	*�ָ�ĳ�ڵ�������¼��Ͷ���
	*@param hoster:���ڵ�
	*/
	void resumeAllActions(cocos2d::Node* hoster);

	/*
	*��ȡ��������
	*/
	inline ObjectLayer* getObjectLayer() { return m_objectLayer; }
	
	/*
	*��ȡ�߼������
	*/
	inline GameLogicLayer* getLogicLayer() { return m_logicLayer; }
private:

	GameLogicLayer* m_logicLayer;
	GameMapLayer* m_mapLayer;
	ObjectLayer* m_objectLayer;
};

#endif // !__GAME_SCENE_H__

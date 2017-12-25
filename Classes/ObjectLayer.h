#pragma once
#ifndef __OBJECT_LAYER_H__
#define __OBJECT_LAYER_H__
#include"PreProcess.h"
#include"Npc.h"
#include<vector>
#include<string>

class ObjectLayer Inherit(cocos2d::Layer)
{
public:
	ObjectLayer();
	~ObjectLayer();

	static ObjectLayer* createWithLevel(const int& level);

	bool init(const int& level);

	void update(float dt);
private:
	/*
	*updateNpcPos();
	*以玩家为基准更新其它对象的位置信息
	*/
	void updateObjectScreenPos();

	/*
	*initLevelObject(const int& level)
	*初始化对象层对象
	*/
	void initLevelObject(const int& level);

	/*
	*releaseNpc();
	*清理对象层
	*/
	void clearObjectLayer();

	std::vector<Npc*> m_npcList;
};

#endif // !__OBJECT_LAYER_H__


#pragma once
#ifndef __OBJECT_LAYER_H__
#define __OBJECT_LAYER_H__
#include"PreProcess.h"
#include"Npc.h"
#include<vector>
#include<string>

/*
*class ObjectLayer
*游戏对象层,用于绘制出玩家以外的其它游戏对象
*/
class ObjectLayer Inherit(cocos2d::Layer)
{
public:
	ObjectLayer();
	~ObjectLayer();

	/*
	*createWithLevel(const int& level);
	*根据地图创建对象层
	*@param level:地图类型
	*/
	static ObjectLayer* createWithLevel(const int& level);

	bool init(const int& level);

	void update(float dt);

	inline std::vector<Npc*>& getNpcList() { return m_npcList; }
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


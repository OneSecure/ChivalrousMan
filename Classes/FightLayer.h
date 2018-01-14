#pragma once
#ifndef  __FIGHT_LAYER_H__
#define __FIGHT_LAYER_H__
#include"PreProcess.h"
#include<string>
#include<vector>

class Monster;

/*
*class FightLayer
*战斗层
*/
class FightLayer Inherit(cocos2d::Layer)
{
public:
	FightLayer();
	~FightLayer();
	/*
	*根据怪物类型创建战斗场景
	*@param monster：怪物
	*/
	static cocos2d::Scene* createFightScene(const std::string& name);

	bool init(const std::string& name);
private:
	void update(float dt);
		
	/*
	*randomNumMonster();
	*生成随机数量的怪物
	*/
	void randomNumMonster(const std::string& name);

	//保存怪物信息链表
	std::vector<Monster*> m_monsterList;
	
	//绘制玩家形象
	cocos2d::Sprite* m_player;
};

#endif // ! __FIGHT_LAYER_HH__


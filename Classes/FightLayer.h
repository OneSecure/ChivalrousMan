#pragma once
#ifndef  __FIGHT_LAYER_H__
#define __FIGHT_LAYER_H__
#include"PreProcess.h"

class Monster;

/*
*class FightLayer
*战斗层
*/
class FightLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(FightLayer)
public:
	/*
	*根据怪物类型创建战斗场景
	*@param monster：怪物
	*/
	static cocos2d::Scene* createFightScene(Monster* monster);

	bool init(Monster* monster);
private:
	
};

#endif // ! __FIGHT_LAYER_HH__


#pragma once
#ifndef  __FIGHT_LAYER_H__
#define __FIGHT_LAYER_H__
#include"PreProcess.h"

class Monster;

/*
*class FightLayer
*ս����
*/
class FightLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(FightLayer)
public:
	/*
	*���ݹ������ʹ���ս������
	*@param monster������
	*/
	static cocos2d::Scene* createFightScene(Monster* monster);

	bool init(Monster* monster);
private:
	
};

#endif // ! __FIGHT_LAYER_HH__


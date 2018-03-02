#pragma once
#ifndef __HURT_VAUE_LAYER_H__
#define __HURT_VAUE_LAYER_H__
#include"PreProcess.h"

/*
*class HurtsValueLayer
*显示伤害值的UI组件
*/
class HurtsValueLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(HurtsValueLayer)
public:
	/*
	*HurtsValueLayer* createWithInfo(Vec2 pos, float hurt);
	*通过位置和伤害值创建
	*@param pos:伤害值显示位置
	*@param hurt：伤害值
	*/
	static HurtsValueLayer* createWithInfo(cocos2d::Vec2 pos, float hurt);

	bool init(cocos2d::Vec2 pos, float hurt);
private:
	/*
	*消失
	*/
	void dead(float dt);
};


#endif // !__HURT_VAUE_LAYER_H__

#pragma once
#ifndef __MINI_MAP_LAYER_H__
#define __MINI_MAP_LAYER_H__
#include"PreProcess.h"

/*
*class WorldMapLayer
*显示世界分布图
*/
class WorldMapLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(WorldMapLayer)
	CREATE_FUNC(WorldMapLayer)
public:
	virtual bool init() override;
private:

};

#endif // !__MINI_MAP_LAYER_H__


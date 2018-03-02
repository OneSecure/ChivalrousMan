#pragma once
#ifndef __MINI_MAP_LAYER_H__
#define __MINI_MAP_LAYER_H__
#include"PreProcess.h"
#include<string>
#include<map>

struct stMap
{
	cocos2d::Vec2 pos;
	std::string name;
};

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
	/*
	*初始化显示地图名字
	*/
	void  initMapInfo();

	std::map<std::string, stMap> m_maps;
};

#endif // !__MINI_MAP_LAYER_H__


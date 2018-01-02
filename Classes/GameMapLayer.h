#pragma once
#ifndef __MAP_LAYER_H__
#define __MAP_LAYER_H__
#include"PreProcess.h"
#include<string>
#include<vector>

/*
*class GameMapLayer
*游戏地图层，主要用于绘制地图
*/
class GameMapLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(GameMapLayer)
	CREATE_FUNC(GameMapLayer)
public:
	bool init() override;

	/*
	*loadMapTexture(std::string name);
	*从文件夹中加载地图纹理
	*@param name:文件夹名称
	*/
	bool loadMapTexture(std::string name);

	/*
	*drawMap(float startx, float starty);
	*绘制处于屏幕之内的地图块
	*@param stratx：绘制的开始x坐标
	*@param starty：绘制的开始y坐标
	*/
	bool drawMap(float startx, float starty);

	/*
	*updateDoorScreenPos();
	*更新地图传送门在屏幕上的位置
	*/
	void updateDoorScreenPos();
private:
	/*
	*创建地图上的传送门
	*/
	void generateDoors();

	/*
	*重置地图块为不可见
	*/
	void resetMap();

	std::vector<cocos2d::Sprite*> m_mapList;

	cocos2d::Node* m_curMaps;

	std::vector<cocos2d::Sprite*> m_doors;
	cocos2d::Sprite* m_door = nullptr;
	cocos2d::Vec2 m_doorPos;
};

#endif // !__MAP_LAYER_H_
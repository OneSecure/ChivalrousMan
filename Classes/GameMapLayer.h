#pragma once
#ifndef __MAP_LAYER_H__
#define __MAP_LAYER_H__
#include"PreProcess.h"
#include<string>
#include<vector>

class GameMapLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(GameMapLayer)
	CREATE_FUNC(GameMapLayer)
public:
	bool init() override;

	void setDoorPos(const cocos2d::Vec2& doorPos);

	bool loadMapTexture(std::string name);

	bool drawMap(float startx, float starty);
private:
	void updateDoorScreenPos();

	void resetMap();

	std::vector<cocos2d::Sprite*> m_mapList;

	cocos2d::Node* m_curMaps;

	cocos2d::Sprite* m_door = nullptr;
	cocos2d::Vec2 m_doorPos;
};

#endif // !__MAP_LAYER_H_
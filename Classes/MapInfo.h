#pragma once
#ifndef __MAP_INFO_H__
#define __MAP_INFO_H__
#include"cocos2d.h"

class MapInfo:public cocos2d::CCObject
{
public:
	static MapInfo* getMapInstance();

	void setFace(cocos2d::Sprite* face);
	
	cocos2d::Sprite* getFace();

	const cocos2d::Size& getMapSize();
private:
	MapInfo();
	~MapInfo();

	cocos2d::Sprite* m_face;
	cocos2d::Size m_mapSize;
	int** m_mapinfo;

	static MapInfo* m_instance;
};

#endif // !__MAP_INFO_H__



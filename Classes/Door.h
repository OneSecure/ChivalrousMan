#pragma once
#ifndef __DOOR_H__
#define __DOOR_H__
#include"PreProcess.h"
#include<string>

class Door
{
public:
	Door();
	~Door();

	float x = 0;
	float y = 0;
	//目的地名称
	std::string dest = "";
	//目的地坐标
	cocos2d::Vec2 destPos;
};

#endif // !__DOOR_H__


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
	//Ŀ�ĵ�����
	std::string dest = "";
	//Ŀ�ĵ�����
	cocos2d::Vec2 destPos;
};

#endif // !__DOOR_H__


#pragma once
#ifndef __NPC_H__
#define __NPC_H__
#include"PreProcess.h"
#include"ReflectNpc.h"

class Npc
{
public:
	Npc();
	~Npc();
	static Npc* CreateClassNpc() { return (new Npc); }

	//世界地图x坐标
	GettingAndSetting(float, m_x, X);
	//世界地图y坐标
	GettingAndSetting(float, m_y, Y);
	//Npc表象
	GettingAndSetting(cocos2d::Sprite*, m_face, Face);
};

#endif // !__NPC_H__


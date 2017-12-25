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

	//�����ͼx����
	GettingAndSetting(float, m_x, X);
	//�����ͼy����
	GettingAndSetting(float, m_y, Y);
	//Npc����
	GettingAndSetting(cocos2d::Sprite*, m_face, Face);
};

#endif // !__NPC_H__


#pragma once
#ifndef __NPC_VALLIGE_H__
#define __NPC_VALLIGE_H__
#include"Npc.h"

/**
*NpcVallige
*Npc�ϴ峤
*/
class NpcVallige Inherit(Npc)
{
	DEC_REFLECT_FUNC(NpcVallige)
public:
	NpcVallige();
	~NpcVallige();
};

#endif // !__NPC_VALLIGE_H__


#pragma once
#ifndef __NPC_BLUE_H__
#define __NPC_BLUE_H__
#include"Npc.h"

/**
*NpcBlue
*¿∂“¬…Ÿ≈Æ
*/
class NpcBlue Inherit(Npc)
{
	DEC_REFLECT_FUNC(NpcBlue)
public:
	NpcBlue();
	~NpcBlue();

	virtual void collisionEvent() override;
private:
};


#endif // !__NPC_BLUE_H__


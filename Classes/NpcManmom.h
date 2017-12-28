#pragma once
#ifndef __NPC_MAMOM_H__
#define __NPC_MAMOM_H__
#include"Npc.h"

/**
*NpcMamom
*²ÆÉñ
*/
class NpcMamom Inherit(Npc)
{
	DEC_REFLECT_FUNC(NpcMamom);
public:
	NpcMamom();
	~NpcMamom();

	virtual void collisionEvent() override;
};

#endif // !__NPC_MAMOM


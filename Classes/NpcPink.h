#pragma once
#ifndef __NPC_PINK_H__
#define __NPC_PINK_H__
#include"Npc.h"

/**
*NpcPink
*∑€“¬…Ÿ≈Æ
*/
class NpcPink Inherit(Npc)
{
	DEC_REFLECT_FUNC(NpcPink)
public:
	NpcPink();
	~NpcPink();

	virtual void collisionEvent() override;

	virtual void endCollisionEvent();

	virtual void talkEndEvent();
private:

};

#endif // !


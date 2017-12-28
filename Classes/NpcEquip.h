#pragma once
#ifndef __NPC_EQUIP_H__
#define __NPC_EQUIP_H__
#include"Npc.h"

/**
*NpcEquip
*装备商人
*/
class NpcEquip Inherit(Npc)
{
	DEC_REFLECT_FUNC(NpcEquip)
public:
	NpcEquip();
	~NpcEquip();
	
	virtual void collisionEvent() override;
private:
};

#endif // !__NPC_EQUIP_H


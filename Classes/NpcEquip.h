#pragma once
#ifndef __NPC_EQUIP_H__
#define __NPC_EQUIP_H__
#include"Npc.h"

/**
*NpcEquip
*װ������
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


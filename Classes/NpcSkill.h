#pragma once
#ifndef __NPC_SKILL_H__
#define __NPC_SKILL_H__
#include"Npc.h"

/**
*NpcSkill
*��������
*/
class NpcSkill Inherit(Npc)
{
	DEC_REFLECT_FUNC(NpcSkill)
public:
	NpcSkill();
	~NpcSkill();

	virtual void collisionEvent() override;
private:

};

#endif // !__NPC_SKILL_H__


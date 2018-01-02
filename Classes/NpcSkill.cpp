#include"NpcSkill.h"
#include"GameData.h"
#include"Commen.h"

DEF_REFLECT_FUNC(NpcSkill)

NpcSkill::NpcSkill()
{
	INIT_TALK_IN_NPC(NpcSkill);
} 

NpcSkill::~NpcSkill()
{

}

void NpcSkill::collisionEvent()
{
	Npc::collisionEvent();
}

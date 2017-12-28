#include"NpcEquip.h"
#include"Commen.h"

DEF_REFLECT_FUNC(NpcEquip)

NpcEquip::NpcEquip()
{
	INIT_TALK_IN_NPC(NpcEquip);
}
  
NpcEquip::~NpcEquip()
{

}

void NpcEquip::collisionEvent()
{
	Npc::collisionEvent();
}
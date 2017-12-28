#include"NpcBlue.h"
#include"Commen.h"

DEF_REFLECT_FUNC(NpcBlue)
  
NpcBlue::NpcBlue()
{
	INIT_TALK_IN_NPC(NpcBlue);
}
  
NpcBlue::~NpcBlue()
{

}

void NpcBlue::collisionEvent()
{
	Npc::collisionEvent();
}

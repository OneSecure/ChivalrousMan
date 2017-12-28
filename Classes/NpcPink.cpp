#include"NpcPink.h"
#include"Commen.h"

DEF_REFLECT_FUNC(NpcPink)
 
NpcPink::NpcPink()
{
	INIT_TALK_IN_NPC(NpcPink);
}

NpcPink::~NpcPink()
{

}

void NpcPink::collisionEvent()
{
	Npc::collisionEvent();
}
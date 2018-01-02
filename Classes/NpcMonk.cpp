#include"NpcMonk.h"
#include"GameData.h"
#include"Commen.h"

DEF_REFLECT_FUNC(NpcMonk)

NpcMonk::NpcMonk()
{
	INIT_TALK_IN_NPC(NpcMonk);
}

NpcMonk::~NpcMonk()
{

}

void NpcMonk::collisionEvent()
{
	Npc::collisionEvent();
}
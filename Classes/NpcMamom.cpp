#include"NpcManmom.h"
#include"Commen.h"

DEF_REFLECT_FUNC(NpcMamom)

NpcMamom::NpcMamom()
{
	INIT_TALK_IN_NPC(NpcMamom);
}
 
NpcMamom::~NpcMamom()
{

}

void NpcMamom::collisionEvent()
{
	Npc::collisionEvent();
}
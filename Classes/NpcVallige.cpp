#include"NpcVallige.h"
#include"GameScene.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"TalkLayer.h"
#include"Commen.h"

DEF_REFLECT_FUNC(NpcVallige)

NpcVallige::NpcVallige()
{
	INIT_TALK_IN_NPC(NpcVallige);
	m_name = "NpcVallige";
}

NpcVallige::~NpcVallige()
{

}

void NpcVallige::collisionEvent()
{
	Npc::collisionEvent();
}

#include"PlayerRun.h"
#include"Commen.h"
#include"GameData.h"
#include"PlayerWait.h"
#include"CameraPlayer.h"
#include"GameDynamicData.h"

PlayerRun::PlayerRun(Sprite* face):
	PlayerState(face)
{

}

PlayerRun::~PlayerRun()
{

}

void PlayerRun::changeAnimation(Dir dir)
{
	switch (dir)
	{
	case Dir::Dir_Left:
	{
		change("RunLeft");
	}
		break;
	case Dir::Dir_Down:
	{
		change("RunDown");
	}
		break;
	case Dir::Dir_Right:
	{
		change("RunRight");
	}
		break;
	case Dir::Dir_Up:
	{
		change("RunUp");
	}
		break;
	default:
		break;
	}
}

PlayerState* PlayerRun::goNextState()
{
	PlayerWait* wait = new PlayerWait(m_playerFace);
	wait->changeAnimation(PlayerDir());
	delete this;
	return wait;
}
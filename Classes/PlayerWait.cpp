#include"PlayerWait.h"
#include"Commen.h"
#include"GameData.h"
#include"PlayerRun.h"
#include"CameraPlayer.h"
#include"GameDynamicData.h"

PlayerWait::PlayerWait(Sprite* face):
	PlayerState(face)
{
}

PlayerWait::~PlayerWait()
{

}

void PlayerWait::changeAnimation(Dir dir)
{
	switch (dir)
	{
	case Dir::Dir_Left:
	{
		change("WaitLeft");
	}
		break;
	case Dir::Dir_Down:
	{
		change("WaitDown");
	}
		break;
	case Dir::Dir_Right:
	{
		change("WaitRight");
	}
		break;
	case Dir::Dir_Up:
	{
		change("WaitUp");
	}
		break;
	default:
		break;
	}
}

PlayerState* PlayerWait::goNextState()
{
	PlayerRun* run=new PlayerRun(m_playerFace);
	run->changeAnimation(PlayerDir());
	delete this;
	return run;
}

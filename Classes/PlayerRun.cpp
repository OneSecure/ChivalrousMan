#include"PlayerRun.h"
#include"Commen.h"
#include"GameData.h"
#include"PlayerWait.h"
#include"CameraPlayer.h"

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
		change(StringValue("RunLeft").c_str());
		break;
	case Dir::Dir_Down:
		change(StringValue("RunDown").c_str());
		break;
	case Dir::Dir_Right:
		change(StringValue("RunRight").c_str());
		break;
	case Dir::Dir_Up:
		change(StringValue("RunUp").c_str());
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
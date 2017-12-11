#include"PlayerWait.h"
#include"Commen.h"
#include"GameData.h"
#include"PlayerRun.h"
#include"CameraPlayer.h"

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
		change(StringValue("WaitLeft").c_str());
		break;
	case Dir::Dir_Down:
		change(StringValue("WaitDown").c_str());
		break;
	case Dir::Dir_Right:
		change(StringValue("WaitRight").c_str());
		break;
	case Dir::Dir_Up:
		change(StringValue("WaitUp").c_str());
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

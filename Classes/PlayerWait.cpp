#include"PlayerWait.h"
#include"Commen.h"
#include"GameData.h"
#include"PlayerRun.h"
#include"CameraPlayer.h"
#include"GameDynamicData.h"

PlayerWait::PlayerWait(Sprite* face,const std::string& playertype) :
	PlayerState(face,playertype)
{
}

PlayerWait::~PlayerWait()
{

}

void PlayerWait::changeAnimation(Dir dir)
{
	m_dir = dir;
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
	PlayerRun* run = new PlayerRun(m_playerFace, m_playerType);
	run->changeAnimation(m_dir);
	delete this;
	return run;
}

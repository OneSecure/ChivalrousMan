#include"GameLogicLayer.h"
#include"Commen.h"
#include"CameraPlayer.h"
#include"FindRoad.h"
#include"MapInfo.h"
#include<stack>

#define UpdateSpeed 60

bool GameLogicLayer::init()
{
	if (Layer::init())
	{
		LISTEN_TOUCH(GameLogicLayer);
		scheduleUpdate();
		return true;
	}
	return false;
}

void  GameLogicLayer::onTouchEnded(Touch *touch, Event *unused_event)
{
	Vec2 pos = touch->getLocation();
	Vec2 targetPos{ PlayerPos.x + (pos.x - PlayerPos.x),PlayerPos.y + (pos.y - PlayerPos.y) };
	targetPos.x /= MapGridW;
	targetPos.y /= MapGridH;
	Vec2 startPos{ PlayerPos.x / MapGridW,PlayerPos.y / MapGridH };
	FindRoad fdroad(startPos, targetPos, GetMapInfo(), MapCountX, MapCountY);
	fdroad.ExecuteAStar();
	if (fdroad.isHasRoad())
	{
		std::stack<Vec2> roadList = fdroad.GetRoadList();
	}	
	int a = 2;
	int b = 2;
	int c = a + b;
	int d = c + 1;
}

void GameLogicLayer::update(float dt)
{
	static float time = 0;
	time += dt*UpdateSpeed;
	if (time >= 1)
	{
		CameraPlayer::getPlayerInstance()->move();
	}
}


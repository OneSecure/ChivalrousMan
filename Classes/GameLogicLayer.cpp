#include"GameLogicLayer.h"
#include"Commen.h"
#include"CameraPlayer.h"
#include"FindRoad.h"
#include"MapInfo.h"
#include"GameData.h"
#include"GameDynamicData.h"
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
	int w = MapGridW;
	Vec2 targetPos{ PlayerPos.x + (pos.x - GetPlayerFace()->getPosition().x),PlayerPos.y + (pos.y - GetPlayerFace()->getPosition().y) };
	targetPos.x /= MapGridW;
	targetPos.y /= MapGridH;
	FOUR_LOSE_FIVE_ADD(targetPos.x);
	FOUR_LOSE_FIVE_ADD(targetPos.y);
	Vec2 startPos{ PlayerPos.x / MapGridW,PlayerPos.y / MapGridH };
	FindRoad fdroad(startPos, targetPos, GetMapInfo(), MapCountX, MapCountY);
	fdroad.ExecuteAStar();
	if (fdroad.isHasRoad())
	{
		SetPlayerMoveRoad(fdroad.GetRoadList());
	}
}

void GameLogicLayer::update(float dt)
{
	static float time = 0;
	time += dt*UpdateSpeed;
	if (time >= 1)
	{
		if (PlayerCanMove())
			PlayerMove();
	}
}
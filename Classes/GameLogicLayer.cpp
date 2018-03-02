#include"GameLogicLayer.h"
#include"Commen.h"
#include"CameraPlayer.h"
#include"FindRoad.h"
#include"MapInfo.h"
#include"GameData.h"
#include"Door.h"
#include"GameDynamicData.h"
#include"ExcessiveScene.h"
#include"GameScene.h"
#include"ObjectLayer.h"
#include"FightLayer.h"
#include<stack>
#include<functional>

#define UpdateSpeed 240

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
		{
			PlayerMove();
			randomMeetMonster();
		}
		UpdateDoorScreenPos();
		checkEntryDoor();
		checkCollisionNpc();
		time = 0;
	}
}

void GameLogicLayer::checkEntryDoor()
{
	std::vector<Door> doors = GetDoorPosInfo();
	int size = doors.size();
	int count = 0;
	for (int i = 0; i <size; ++i)
	{
		float dis = ccpDistance(PlayerPos, ccp(doors[i].x, doors[i].y));
		if (dis < 40)
		{
			SetFloatData("DestX", doors[i].destPos.x);
			SetFloatData("DestY", doors[i].destPos.y);
			unscheduleUpdate();
			gotoDestMap(doors[i].dest);
			break;
		}
	}
}

void GameLogicLayer::gotoDestMap(const std::string& dest)
{
	std::function<bool(void)> func = [] {return true; };
	ExcessiveScene* ex = nullptr;
	if (dest == "map1")
	{
		ex = ExcessiveScene::createExcessice(LEVEL_ONE, func, 1);
	}
	else if (dest == "map2")
	{
		ex = ExcessiveScene::createExcessice(LEVEL_TWO, func, 1);
	}
	else if (dest == "map3")
	{
		ex = ExcessiveScene::createExcessice(LEVEL_THREE, func, 1);
	}
	else if (dest == "map4")
	{
		ex = ExcessiveScene::createExcessice(LEVEL_FOUR, func, 1);
	}
	else if (dest == "map5")
	{
		ex = ExcessiveScene::createExcessice(LEVEL_FIVE, func, 1);
	}
	Director::getInstance()->replaceScene(ex);
}

void GameLogicLayer::checkCollisionNpc()
{
	GameScene* gs = (GameScene*)getParent();
	std::vector<Npc*>& npclist = gs->getObjectLayer()->getNpcList();
	for each (auto var in npclist)
	{
		float dis = ccpDistance(PlayerPos, ccp(var->getX(), var->getY()));
		if (dis < 120)
		{
			if (!var->getIsCollision())
			{
				var->collisionEvent();
			}
		}
		else
		{
			if (var->getIsCollision())
			{
				var->endCollisionEvent();
			}
		}
	}
}

void GameLogicLayer::randomMeetMonster()
{
	//产生怪物间隔
	static int interval = 0;
	std::random_device rand;
	if (GetIntData("CurMap")>=LEVEL_THREE)
	{
		if (interval > 5)
		{
			int randnum = rand() % 100;
			if (randnum < 2)
			{
				unscheduleUpdate();
				SetFloatData("DestX", PlayerPos.x);
				SetFloatData("DestY", PlayerPos.y);
				auto fightScene = FightLayer::createFightScene(monsterName());
				auto reScene = TransitionFadeUp::create(0.5, fightScene);
				Director::getInstance()->replaceScene(reScene);
			}
			interval = 0;
		}
	}
	interval++;
}

std::string  GameLogicLayer::monsterName()
{
	std::random_device rand;
	switch (GetIntData("CurMap"))
	{
	case LEVEL_THREE:
	{
		std::string name[] = { "Ghost","BlackDragon","Dragon" };
		int index = rand() % 3;
		return name[index];
	}
	case LEVEL_FOUR:
	{
		std::string name[] = { "Kougamon","Lion","Minotaur" };
		int index = rand() % 3;
		return name[index];
	}
	case LEVEL_FIVE:
	{
		std::string name[] = { "Octopus","Pterosaur","SkeletonMaster","TarrasqueMessenger" };
		int index = rand()%4;
		return name[index];
	}
	default:
		return "";
	}
}
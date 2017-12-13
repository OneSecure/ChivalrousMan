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
		generateUserInterface();
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

void GameLogicLayer::generateUserInterface()
{
	auto size = SCREEN;
	auto headFrame = Sprite::create(StringValue("HeadFrame"));
	headFrame->setPosition(headFrame->getContentSize().width*0.5 + 10, size.height - headFrame->getContentSize().height*0.5 - 15);
	this->addChild(headFrame);
	char headname[40] = { 0 };
	sprintf_s(headname, "%sHead", GetStringData("PlayerType").c_str());
	m_head = MenuItemImage::create(StringValue(headname), StringValue(headname));
	m_head->setPosition(headFrame->getPosition().x -5, headFrame->getPosition().y + 5);
	auto menu = Menu::create();
	menu->addChild(m_head);
	menu->setPosition(0, 0);

	auto labelgrade = LabelTTF::create(StringValue("GradeText"), "¿¬Ìå", 20);
	labelgrade->setColor(ccc3(0, 0, 0));
	labelgrade->setPosition(labelgrade->getContentSize().width*0.5 + 5, size.height - headFrame->getContentSize().height - 25);
	this->addChild(labelgrade);
	m_grade = LabelTTF::create("1", "¿¬Ìå", 20);
	m_grade->setPosition(labelgrade->getPosition().x + labelgrade->getContentSize().width, labelgrade->getPosition().y);
	this->addChild(m_grade);
	
	this->addChild(menu);
}
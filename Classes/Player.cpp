#include"Player.h"
#include"GameDynamicData.h"
#include"MapInfo.h"
#include"Commen.h"

Player* Player::m_instance = nullptr;

Player::Player()
{
	m_pos.x = 100;
	m_pos.y = 200;
}

Player::~Player()
{

}

Player* Player::getPlayerInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new Player;
	}
	return m_instance;
}

void Player::setFace(cocos2d::Sprite* face)
{
	m_face = face;
	m_face->setPosition(changeMapPosToUI());
}

Sprite* Player::getFace()
{
	return m_face;
}

Vec2 Player::changeMapPosToUI()
{
	Size sizeUI = SCREEN;
	Size sizeMap{ MapInfo::getMapInstance()->getMapSize().width
		,MapInfo::getMapInstance()->getMapSize().height };
	Vec2 pos{ sizeUI.width*0.5f,sizeUI.height*0.5f };
	if (m_pos.x <= sizeUI.width*0.5)
	{
		pos.x = m_pos.x;
	}
	else if (m_pos.x >= sizeMap.width - sizeUI.width*0.5)
	{
		pos.x = sizeUI.width - sizeMap.width + m_pos.x;
	}

	if (m_pos.y <= sizeUI.height*0.5)
	{
		pos.y = m_pos.y;
	}
	else if (m_pos.y >= sizeMap.height - sizeUI.height*0.5)
	{
		pos.y = sizeUI.height - sizeMap.height + m_pos.y;
	}
	return pos;
}

bool Player::move()
{
	Animal::move();
	m_face->setPosition(changeMapPosToUI());
	return true;
}
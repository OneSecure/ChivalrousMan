#include"CameraPlayer.h"
#include"MapInfo.h"
#include"GameMapLayer.h"
#include"Commen.h"

CameraPlayer* CameraPlayer::m_instance = nullptr;

CameraPlayer::CameraPlayer()
{
	m_pos.x = 100;
	m_pos.y = 100;
}

CameraPlayer::~CameraPlayer()
{

}

CameraPlayer* CameraPlayer::getPlayerInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new CameraPlayer;
	}
	return m_instance;
}

void CameraPlayer::setFace(cocos2d::Sprite* face)
{
	m_face = face;
	std::pair<Vec2, Vec2> pos = changeMapPosToUI();
	m_face->setPosition(pos.first);
	MapLayer->drawMap(pos.second.x, pos.second.y);
}

Sprite* CameraPlayer::getFace()
{
	return m_face;
}

std::pair<Vec2,Vec2> CameraPlayer::changeMapPosToUI()
{
	Size sizeUI = SCREEN;
	Size sizeMap{ MapWidth,MapHeight };
	std::pair<Vec2, Vec2> pos;
	pos.first.x = sizeUI.width*0.5f;
	pos.first.y = sizeUI.height*0.5f;
	pos.second.x = m_pos.x - sizeUI.width*0.5f;
	pos.second.y = m_pos.y - sizeUI.height*0.5f;
	if (m_pos.x <= sizeUI.width*0.5)
	{
		pos.first.x = m_pos.x;
		pos.second.x = 0;
	}
	else if (m_pos.x >= sizeMap.width - sizeUI.width*0.5)
	{
		pos.first.x = sizeUI.width - sizeMap.width + m_pos.x;
		pos.second.x = sizeMap.width - sizeUI.width;
	}

	if (m_pos.y <= sizeUI.height*0.5)
	{
		pos.first.y = m_pos.y;
		pos.second.y = 0;
	}
	else if (m_pos.y >= sizeMap.height - sizeUI.height*0.5)
	{
		pos.first.y = sizeUI.height - sizeMap.height + m_pos.y;
		pos.second.y = sizeMap.height - sizeUI.height;
	}

	return pos;
}

bool CameraPlayer::move()
{
	if (Animal::move())
	{
		std::pair<Vec2, Vec2> pos = changeMapPosToUI();
		m_face->setPosition(pos.first);
		MapLayer->drawMap(pos.second.x, pos.second.y);
	}
	return true;
}

void CameraPlayer::moveToTarget(const cocos2d::Vec2& target)
{
	
}

void CameraPlayer::release()
{
	RELEASE_NULL(m_instance);
}

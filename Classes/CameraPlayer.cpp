#include"CameraPlayer.h"
#include"MapInfo.h"
#include"GameMapLayer.h"
#include"Commen.h"
#include"PlayerState.h"
#include"PlayerWait.h"
#include"PlayerRun.h"

CameraPlayer* CameraPlayer::m_instance = nullptr;

CameraPlayer::CameraPlayer()
{
	m_pos.x = 100;
	m_pos.y = 100;
	m_flag = 0;
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
	m_state = new PlayerWait(m_face);
	m_state->changeAnimation(Dir::Dir_Down);
	m_face->setAnchorPoint(ccp(0.5, 0.1));
	std::pair<Vec2, Vec2> pos = changeMapPosToUI();
	m_face->setPosition(pos.first);
	MapLayer->drawMap(pos.second.x, pos.second.y);
}

bool CameraPlayer::trunDir(const float& angle)
{
	if (Animal::trunDir(angle))
	{
		m_state->changeAnimation(m_dir);
		return true;
	}
	return false;
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
		return true;
	}
	return false;
}

void CameraPlayer::goNext()
{
	Vec2 pos = m_roadList.top();
	int w = MapGridW;
	int h = MapGridH;
	pos.x *= w;
	pos.y *= h;
	pos.x += w*0.5;
	pos.y += h*0.5;
	if (abs(pos.x - m_pos.x) < w*0.5&&abs(pos.y - m_pos.y) < h*0.5)
	{
		m_roadList.pop();
	}
	float angle = CalcAngle(m_pos, pos);
	trunDir(angle);
}

bool CameraPlayer::canMove()
{
	if (!m_roadList.empty())
	{
		goNext();
		if (!m_flag)
			m_state = m_state->goNextState();
		m_flag = 1;
		return true;
	}
	if (m_flag)
		m_state = m_state->goNextState();
	m_flag = 0;
	return false;
}

void CameraPlayer::release()
{
	RELEASE_NULL(m_instance);
}

void CameraPlayer::setMoveRoad(std::stack<cocos2d::Vec2>& road)
{
	m_roadList = road;
}

float  CameraPlayer::CalcAngle(cocos2d::Vec2 start, cocos2d::Vec2 target)
{
	if (start.x == target.x)
	{
		return start.y < target.y ? 0 : PI;
	}
	if (start.y == target.y)
	{
		return start.x < target.x ? PI : PI*1.5;
	}
	float dx = target.x - start.x;
	float dy = target.y - start.y;
	float angle = atanf(abs(dx / dy));
	if (start.x < target.x&&start.y < target.y)
	{
		return angle;
	}
	else if (start.x<target.x&&start.y>target.y)
	{
		return PI - angle;
	}
	else if (start.x > target.x&&start.y > target.y)
	{
		return PI + angle;
	}
	else
	{
		return 2 * PI - angle;
	}
}
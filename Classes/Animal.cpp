#include"Animal.h"
#include"Commen.h"

Animal::Animal()
{
	m_vx = 0;
	m_vy = 0;
}

Animal::~Animal()
{

}

const float& Animal::getVx() 
{
	return m_vx;
}

const float& Animal::getVy()
{
	return m_vy;
}

bool Animal::move()
{
	if (m_vx == 0 && m_vy == 0)
	{
		return false;
	}
	m_pos.x += m_vx;
	m_pos.y += m_vy;
	return true;
}

void Animal::setVelocity(const float& v)
{
	m_v = v;
}

bool Animal::trunDir(const float& angle)
{
	bool bRet = false;
	if (m_vx == 0 && m_vy == 0)
	{
		bRet = true;
	}
	m_vx = m_v*sinf(angle);
	m_vy = m_v*cosf(angle);
	Dir newDir = abs(m_vx) > abs(m_vy) ? (m_vx > 0 ? 
		Dir::Dir_Right : Dir::Dir_Left) :
		(m_vy > 0 ? Dir::Dir_Up : Dir::Dir_Down);
	if (!bRet)
		bRet = (m_dir != newDir);
	m_dir = newDir;
	return bRet;
}

cocos2d::Vec2& Animal::getPos()
{
	return m_pos;
}

const Dir& Animal::getDir()
{
	return m_dir;
}

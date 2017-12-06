#include"Animal.h"
#include"Commen.h"

Animal::Animal()
{

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
	m_pos.x += m_vx;
	m_pos.y += m_vy;
	return true;
}

void Animal::setVelocity(const float& v)
{
	m_v = v;
}

void Animal::trunDir(const float& angle)
{
	m_vx = m_v*sinf(angle);
	m_vy = m_v*cosf(angle);
}
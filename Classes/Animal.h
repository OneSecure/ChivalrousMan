#pragma once
#ifndef __ANIMAL_H__
#define __ANIMAL_H__
#include"PreProcess.h"

class Animal
{
public:
	enum class Dir
	{
		Dir_Left,
		Dir_Right,
		Dir_Up,
		Dir_Down,
	};
	Animal();
	~Animal();

	virtual const float& getVx();

	virtual const float& getVy();
	
	virtual bool move();

	virtual void setVelocity(const float& v);

	virtual void trunDir(const float& angle);

	virtual cocos2d::Vec2& getPos();
protected:
	cocos2d::Vec2 m_pos;
	float m_life;
	float m_atk;
	Dir m_dir;
	float m_vx;
	float m_vy;
	float m_v;
};

#endif // !__ANIMAL_H__


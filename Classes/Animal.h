#pragma once
#ifndef __ANIMAL_H__
#define __ANIMAL_H__
#include"PreProcess.h"

class Animal
{
public:
	Animal();
	virtual ~Animal();
	 
	/*
	*getVx()
	*获取x轴上的分速度
	*@return float：x轴上的分速度
	*/
	virtual const float& getVx();

	/*
	*getVy()
	*获取在y轴上的分速度
	*@return float：y轴上的分速度
	*/
	virtual const float& getVy();

	/*
	*move()
	*移动
	*@return bool：是否真的移动了
	*/
	virtual bool move();

	/*
	*setVelocity(float& v)
	*设置合速度
	*@param v：合速度大小
	*/
	virtual void setVelocity(const float& v);

	/*
	*trunDir(float& angle)
	*改变移动方向
	*新的转向角
	*@param angle:转向角度
	*@return bool：返回与上一次相比是否改变方向
	*/
	virtual bool trunDir(const float& angle);
	
	/*
	*getPos()
	*获取世界位置
	*@return Vec2：返回世界位置
	*/
	virtual cocos2d::Vec2& getPos();

	/*
	*getDir();
	*获取方向
	*/
	virtual const Dir& getDir();
protected:
	cocos2d::Vec2 m_pos;
	Dir m_dir;
	float m_vx;
	float m_vy;
	float m_v;
};

#endif // !__ANIMAL_H__


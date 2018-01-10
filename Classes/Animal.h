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
	*��ȡx���ϵķ��ٶ�
	*@return float��x���ϵķ��ٶ�
	*/
	virtual const float& getVx();

	/*
	*getVy()
	*��ȡ��y���ϵķ��ٶ�
	*@return float��y���ϵķ��ٶ�
	*/
	virtual const float& getVy();

	/*
	*move()
	*�ƶ�
	*@return bool���Ƿ�����ƶ���
	*/
	virtual bool move();

	/*
	*setVelocity(float& v)
	*���ú��ٶ�
	*@param v�����ٶȴ�С
	*/
	virtual void setVelocity(const float& v);

	/*
	*trunDir(float& angle)
	*�ı��ƶ�����
	*�µ�ת���
	*@param angle:ת��Ƕ�
	*@return bool����������һ������Ƿ�ı䷽��
	*/
	virtual bool trunDir(const float& angle);
	
	/*
	*getPos()
	*��ȡ����λ��
	*@return Vec2����������λ��
	*/
	virtual cocos2d::Vec2& getPos();

	/*
	*getDir();
	*��ȡ����
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


#pragma once
#ifndef __REAL_SKILL_H__
#define __REAL_SKILL_H__
#include"PreProcess.h"

#define SKILL__FUNC(__TYPE__)   \
public:    \
static __TYPE__* __TYPE__::create(cocos2d::Layer* parent, const float& baseattack)      \
{   \
__TYPE__* pRet = new __TYPE__;    \
if (pRet&&pRet->init(parent, baseattack))   \
{     \
	pRet->autorelease(); return pRet;}else     \
{  delete pRet;  pRet = nullptr; return nullptr;  } }   \
bool init(cocos2d::Layer* parent, const float& baseattack);

class RealSkill Inherit(cocos2d::Sprite)
{
public:
	RealSkill();
	virtual ~RealSkill();

	/*
	*ÏûÊ§
	*/
	virtual void died(float dt);
protected:
	cocos2d::Layer* m_parent;
	float m_baseattack;
};

#endif // !__REAL_SKILL_H__


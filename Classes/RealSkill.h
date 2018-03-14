#pragma once
#ifndef __REAL_SKILL_H__
#define __REAL_SKILL_H__
#include"PreProcess.h"
#include<string>

#define SKILL__FUNC(__TYPE__)   \
public:    \
static __TYPE__* __TYPE__::create(cocos2d::Layer* parent,cocos2d::CCObject* towho, const float& baseattack)      \
{   \
__TYPE__* pRet = new __TYPE__;    \
if (pRet&&pRet->init(parent,towho, baseattack))   \
{     \
	pRet->autorelease(); return pRet;}else     \
{  delete pRet;  pRet = nullptr; return nullptr;  } }   \
bool init(cocos2d::Layer* parent,cocos2d::CCObject* towho, const float& baseattack);

class RealSkill Inherit(cocos2d::Sprite)
{
public:
	RealSkill();
	virtual ~RealSkill();

	/*
	*��ʧ
	*/
	virtual void died(float dt);

	/*
	*Ԥ���ؼ��ܶ���
	*/
	static void loadAnimation(std::string name, int nums, float delay);

	/*
	*��ȡ���ܶ���
	*@param key:����keyֵ
	*/
	static cocos2d::Animation* getAnimation(std::string key);
protected:
	cocos2d::Layer* m_parent;
	cocos2d::CCObject* m_towho;
	float m_baseattack;
};

#endif // !__REAL_SKILL_H__


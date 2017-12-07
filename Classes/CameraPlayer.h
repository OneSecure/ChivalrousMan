#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include"Animal.h"
#include<iostream>
#include<utility>

#define GetPlayerFace CameraPlayer::getPlayerInstance()->getFace
#define SetPlayerFace CameraPlayer::getPlayerInstance()->setFace
#define PlayerTrunDir CameraPlayer::getPlayerInstance()->trunDir
#define SetPlayerVelocity CameraPlayer::getPlayerInstance()->setVelocity
#define PlayerPos CameraPlayer::getPlayerInstance()->getPos()

class CameraPlayer:public Animal
{
public:
	static CameraPlayer* getPlayerInstance();

	void setFace(cocos2d::Sprite* face);

	cocos2d::Sprite* getFace();

	std::pair<cocos2d::Vec2,cocos2d::Vec2>  changeMapPosToUI();

	bool move() override;

	void moveToTarget(const cocos2d::Vec2& target);

	static void release();
private:
	CameraPlayer();
	~CameraPlayer();

	cocos2d::Sprite* m_face;
	static CameraPlayer* m_instance;
};

#endif // !__PLAYER_H__


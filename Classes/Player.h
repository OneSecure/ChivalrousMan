#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include"Animal.h"

class Player:public Animal
{
public:
	static Player* getPlayerInstance();

	void setFace(cocos2d::Sprite* face);

	cocos2d::Sprite* getFace();

	cocos2d::Vec2 changeMapPosToUI();

	bool move() override;
private:
	Player();
	~Player();

	cocos2d::Sprite* m_face;
	static Player* m_instance;
};

#endif // !__PLAYER_H__


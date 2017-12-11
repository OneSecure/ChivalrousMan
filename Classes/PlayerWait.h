#pragma once
#ifndef __PLAYER_WAIT_H__
#define __PLAYER_WAIT_H__
#include"PlayerState.h"

class PlayerWait:public PlayerState
{
public:
	PlayerWait(cocos2d::Sprite* face);
	~PlayerWait();

	virtual void changeAnimation(Dir dir) override;
	
	virtual PlayerState* goNextState() override;
private:

};

#endif // !__PLAYER_WAIT_H


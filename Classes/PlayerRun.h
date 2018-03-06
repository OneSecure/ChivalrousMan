#pragma once
#ifndef __PLAYER_RUN_H__
#define __PLAYER_RUN_H__
#include"PlayerState.h"


class PlayerRun:public PlayerState
{
public:
	PlayerRun(cocos2d::Sprite* face,const std::string& playertype);
	~PlayerRun();

	virtual void changeAnimation(Dir dir) override; 

	virtual PlayerState* goNextState() override;
private:
};

#endif // !__PLAYER_RUN_H


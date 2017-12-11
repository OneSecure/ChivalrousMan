#pragma once
#ifndef __PLAYER_STATE_H__
#define __PLAYER_STATE_H__
#include"PreProcess.h"

class PlayerState
{
public:
	PlayerState(cocos2d::Sprite* face);
	virtual ~PlayerState();

	/*
	*changeAnimation(Dir dir);
	*改变动画
	*@param dir：改变到哪个方向的动画
	*/
	virtual void changeAnimation(Dir dir) = 0;

	/*
	*进入下一个状态
	*goNextState()
	*@return PlayerState*：下一状态
	*/
	virtual PlayerState* goNextState() = 0;
protected:
	/*
	*执行改变动画操作
	*/
	void change(const char* name);

	cocos2d::Sprite* m_playerFace;
};

#endif // !

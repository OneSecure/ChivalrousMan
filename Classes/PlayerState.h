#pragma once
#ifndef __PLAYER_STATE_H__
#define __PLAYER_STATE_H__
#include"PreProcess.h"

class PlayerState
{
public:
	PlayerState(cocos2d::Sprite* face,const std::string& playertype);
	virtual ~PlayerState();

	/*
	*changeAnimation(Dir dir);
	*�ı䶯��
	*@param dir���ı䵽�ĸ�����Ķ���
	*/
	virtual void changeAnimation(Dir dir) = 0;

	/*
	*������һ��״̬
	*goNextState()
	*@return PlayerState*����һ״̬
	*/
	virtual PlayerState* goNextState() = 0;
protected:
	/*
	*ִ�иı䶯������
	*/
	void change(const char* name);

	cocos2d::Sprite* m_playerFace;
	std::string m_playerType;
	Dir m_dir;
};

#endif // !

#pragma once
#ifndef __PLAYER_LIST_H__
#define  __PLAYER_LIST_H__
#include"PreProcess.h"

/*
*class PlayerListLayer
*��ʾ��Χ����б�
*/
class PlayerListLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(PlayerListLayer)
	CREATE_FUNC(PlayerListLayer)
public:
	bool init();
	
private:
	void initPlayerItem(cocos2d::Vec2 basePos);
};

#endif // !__PLAYER_LIST_H__


#pragma once
#ifndef __PLAYER_ITEM_H__
#define __PLAYER_ITEM_H__
#include"PreProcess.h"

struct  Player_Info;

class PlayerItem Inherit(cocos2d::Node)
{
	CLASS_ESSENTAIL(PlayerItem)
public:
	/*
	*通过玩家信息创建Item
	*/
	static PlayerItem* create(const Player_Info& info);
	
	bool init(const Player_Info& info);
private:
	/*
	*头像按下回调函数
	*/
	void onHeadClick(cocos2d::CCObject* sender);

	/*
	*私聊按钮点击回调函数
	*/
	void onPrivateTalkClick(cocos2d::CCObject* sender);

	/*
	*组队按钮点击回调函数
	*/
	void onMakeTeamClick(cocos2d::CCObject* sender);

	PROPERTY__REF(int, m_fd, Fd)
};

#endif // !__PLAYER_ITEM_H__

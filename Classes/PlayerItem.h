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
	*ͨ�������Ϣ����Item
	*/
	static PlayerItem* create(const Player_Info& info);
	
	bool init(const Player_Info& info);
private:
	/*
	*ͷ���»ص�����
	*/
	void onHeadClick(cocos2d::CCObject* sender);

	/*
	*˽�İ�ť����ص�����
	*/
	void onPrivateTalkClick(cocos2d::CCObject* sender);

	/*
	*��Ӱ�ť����ص�����
	*/
	void onMakeTeamClick(cocos2d::CCObject* sender);

	PROPERTY__REF(int, m_fd, Fd)
};

#endif // !__PLAYER_ITEM_H__

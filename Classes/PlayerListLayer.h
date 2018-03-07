#pragma once
#ifndef __PLAYER_LIST_H__
#define  __PLAYER_LIST_H__
#include"PreProcess.h"
#include<vector>

class  PlayerItem;

/*
*class PlayerListLayer
*显示周围玩家列表
*/
class PlayerListLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(PlayerListLayer)
	CREATE_FUNC(PlayerListLayer)
public:
	bool init();
	
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
private:
	void initPlayerItem(cocos2d::Vec2 basePos);

	void onScrollBarClick(cocos2d::CCObject* sender);

	std::vector<PlayerItem*> m_itemlist;
	cocos2d::MenuItemImage* m_scrollBar; 
	cocos2d::Vec2 m_topPos;            //滚动条的位置上限
	cocos2d::Vec2 m_bottomPos;      //滚动条的位置下限
	float m_pagenums = 6;                //一页所能存放的最大Item数
};

#endif // !__PLAYER_LIST_H__


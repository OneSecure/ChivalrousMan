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
	
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
private:
	void initPlayerItem();

	void onScrollBarClick(cocos2d::CCObject* sender);

	/*
	*moveItem(float dy);
	*移动列表中的item
	*@param dy：移动的距离
	*/
	void moveItem(float dy);

	/*
	*void recoverItem(float dy);
	*还原item的位置
	*还原时所进行的偏移
	*/
	void recoverItem(float dy);

	std::vector<PlayerItem*> m_itemlist;
	cocos2d::MenuItemImage* m_scrollBar; 
	cocos2d::Vec2 m_basePos;    //
	cocos2d::Vec2 m_topPos;            //滚动条的位置上限
	cocos2d::Vec2 m_bottomPos;      //滚动条的位置下限
	float m_pagenums = 6;                //一页所能存放的最大Item数
	bool m_click = false;
	bool m_scrollClick = false;
	cocos2d::Vec2 m_startPos;          //开始点击的位置
	cocos2d::Vec2 m_startScrollPos; //点击开始ScrollBar的位置
	float m_dy = 0;
};

#endif // !__PLAYER_LIST_H__


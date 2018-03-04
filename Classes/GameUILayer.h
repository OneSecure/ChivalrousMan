#pragma once
#ifndef __GAME_UI_LAYER_H__
#define __GAME_UI_LAYER_H__
#include"PreProcess.h"

/*
*class GameUILayer
*游戏界面的UI层，用于与用户进行交互
*/
class GameUILayer:public cocos2d::Layer,
	public  cocos2d::TextFieldDelegate
{
	CLASS_ESSENTAIL(GameUILayer)
	CREATE_FUNC(GameUILayer)
public:
	bool init() override;

	/*
	*resetMenulayer();
	*重设菜单层为false
	*/
	void resetMenulayer();
private:
	/*
	*doWorldTalkMsg();
	*处理世界聊天发来的消息
	*/
	void doWorldTalkMsg();

	/*
	*generateUserInterface();
	*生成用户界面
	*/
	void generateUserInterface();

	/*
	*世界地图图标点击回调函数
	*/
	void onMapIconClickCallBack(cocos2d::CCObject* sender);

	/*
	*背包图标点击回调函数
	*/
	void onBackPackClickCallBack(cocos2d::CCObject* sender);

	/*
	*技能图标点击回调函数
	*/
	void onSkillClickCallBack(cocos2d::CCObject* sender);

	/*
	*头像点击回调函数
	*/
	void onHeadClickCallBack(cocos2d::CCObject* sender);

	/*
	*菜单按钮点击回调函数
	*/
	void onMenuClickCallBack(cocos2d::CCObject* sender);

	/*
	*点击发送按钮回调函数
	*/
	void onSendClickCallBack(cocos2d::CCObject* sender);

	/*
	*任务图标按下回调函数
	*/
	void onTaskIconClickCallback(cocos2d::CCObject* sender);

	void update(float dt) override;
	
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	virtual bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF * sender);

	virtual bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF * sender);

	cocos2d::LabelTTF* m_roleName;                   //角色名
	cocos2d::ProgressTimer* m_bloodBar;           //血条
	cocos2d::ProgressTimer* m_manaBar;           //魔条
	cocos2d::ProgressTimer* m_expBar;              //经验条
	cocos2d::MenuItemImage* m_head;              //头像
	cocos2d::LabelTTF* m_name;                         //角色名
	cocos2d::LabelTTF* m_grade;                         //等级
	cocos2d::MenuItemImage* m_worldMap;     //世界地图
	cocos2d::MenuItemImage* m_backpack;       //背包
	cocos2d::MenuItemImage* m_skill;                //技能
	cocos2d::MenuItemImage* m_taskItem;        //任务
	cocos2d::Sprite* m_talkFrame;   //世界聊天框
	cocos2d::MenuItemImage* m_sendBtn;  //发送按钮
	cocos2d::TextFieldTTF* m_editFrame;       //编辑消息框
	cocos2d::MenuItemImage* m_menuBtn;
	cocos2d::LabelTTF* m_glodlabel;    //显示玩家金币
	
	bool m_isclickGameMenuLayer = false;
	bool m_isclickSkillLayer = false;
	bool m_isclickBackPackLayer = false;
	bool m_isclickWorldMapLayer = false;
	bool m_isclickRoleInfoLayer = false;
	bool m_isclickMapLayer = false;
	bool m_isclickTaskLayer = false;
	bool m_isClickLayer = false;
};

#endif // !__GAME_UI_LAYER_H__


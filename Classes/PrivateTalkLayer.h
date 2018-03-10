#pragma once
#ifndef __PRIVATE_TALK_LAYER_H__
#define __PRIVATE_TALK_LAYER_H__
#include"PreProcess.h"
#include<list>

/*
*class PrivateTalkLayer
*私聊层，显示私聊消息
*/
class PrivateTalkLayer Inherit(cocos2d::Layer),
	public  cocos2d::TextFieldDelegate
{
	CLASS_ESSENTAIL(PrivateTalkLayer)
public:
	/*
	*创建私聊层
	*/
	static PrivateTalkLayer* create(const int& fd);

	bool init(const int& fd);

	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	virtual bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF * sender);

	virtual bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF * sender);

	/*
	*发送按钮点击回调函数
	*/
	void onSendBtnClick(cocos2d::CCObject* sender);

	/*
	*关闭按钮点击回调函数
	*/
	void onCloseBtnClick(cocos2d::CCObject* sender);

	/*
	*向消息列表中添加消息
	*/
	void addMsg(std::string who, std::string msg);
private:
	/*
	*初始化聊天列表
	*/
	void initMsgList();

	int m_fd;

	cocos2d::TextFieldTTF* m_editFrame;

	std::list<cocos2d::LabelTTF*> m_msgList;
	cocos2d::Vec2 m_basePos;
};

#endif


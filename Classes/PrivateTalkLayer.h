#pragma once
#ifndef __PRIVATE_TALK_LAYER_H__
#define __PRIVATE_TALK_LAYER_H__
#include"PreProcess.h"
#include<list>

/*
*class PrivateTalkLayer
*˽�Ĳ㣬��ʾ˽����Ϣ
*/
class PrivateTalkLayer Inherit(cocos2d::Layer),
	public  cocos2d::TextFieldDelegate
{
	CLASS_ESSENTAIL(PrivateTalkLayer)
public:
	/*
	*����˽�Ĳ�
	*/
	static PrivateTalkLayer* create(const int& fd);

	bool init(const int& fd);

	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	virtual bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF * sender);

	virtual bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF * sender);

	/*
	*���Ͱ�ť����ص�����
	*/
	void onSendBtnClick(cocos2d::CCObject* sender);

	/*
	*�رհ�ť����ص�����
	*/
	void onCloseBtnClick(cocos2d::CCObject* sender);

	/*
	*����Ϣ�б��������Ϣ
	*/
	void addMsg(std::string who, std::string msg);
private:
	/*
	*��ʼ�������б�
	*/
	void initMsgList();

	int m_fd;

	cocos2d::TextFieldTTF* m_editFrame;

	std::list<cocos2d::LabelTTF*> m_msgList;
	cocos2d::Vec2 m_basePos;
};

#endif


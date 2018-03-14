#pragma once
#ifndef __THING_H__
#define __THING_H__
#include"PreProcess.h"
#include<vector>
#include<string>

/*
*��Ʒ����
*class Thing
*/
class Thing Inherit(cocos2d::MenuItemImage)
{
public:
	Thing();
	Thing(const std::string &name);
	virtual ~Thing();

	/*
	*showDetail();
	*��ʾ��Ʒ����
	*/
	virtual void showDetail(cocos2d::Node* node);

	virtual std::vector<std::string>& getDetails();

	/*
	*��Ʒ��ʹ��ʱ����
	*/
	virtual float beUse(cocos2d::CCObject* obj, cocos2d::CCObject* who = nullptr, cocos2d::CCObject* towho = nullptr);

	static std::string getfileName(const std::string& name);
protected:
	/*
	*initDetails(const std::string& name)
	*��ʼ��ϸ������
	*@param name����Ʒ��
	*/
	virtual void initDetails(const std::string& name);

	//ϸ������
	std::vector<std::string> m_details;
	 //����۸�
	PROPERTY__REF(float, m_buyglod, buyglod)
	//�����۸�
	PROPERTY__REF(float, m_sellglod, sellglod)
	//����
	PROPERTY__REF(std::string,m_name,name)
	//�����һ��
	PROPERTY__REF(std::string,m_firsttext,firsttext)
};

#endif // !__THING_H__


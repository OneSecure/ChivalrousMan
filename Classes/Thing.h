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
	Thing(const std::string &name);
	virtual ~Thing();

	/*
	*showDetail();
	*��ʾ��Ʒ����
	*/
	virtual void showDetail(cocos2d::Node* node);

	virtual std::vector<std::string>& getDetails();

	static std::string getName(const std::string& name);
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
};

#endif // !__THING_H__


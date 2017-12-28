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
	/*
	*createWithImage(const std::string& filename)
	*ͨ���ļ�������һ����������
	*@param filename:�ļ���
	*/
	static Thing* createWithImage(const std::string& filename);

	Thing();
	virtual ~Thing();

	virtual bool init(const std::string& filename);

	/*
	*showDetail();
	*��ʾ��Ʒ����
	*/
	virtual void showDetail();
private:
	std::vector<std::string> m_details;
};

#endif // !__THING_H__


#pragma once
#ifndef __TIP_LAYER_H__
#define __TIP_LAYER_H__
#include"PreProcess.h"
#include<string>

/*
*class TipLayer
*��ʾ��
*/
class TipLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(TipLayer)
public:
	CreateWithParam(TipLayer,std::string,tiptext)

	bool init(const std::string& tiptext);
private:
	/*
	*killSelf(float dt);
	*�����Լ�
	*/
	void killSelf(float dt);
};

#endif // !__TIP_LAYER_H__


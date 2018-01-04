#pragma once
#ifndef __TIP_LAYER_H__
#define __TIP_LAYER_H__
#include"PreProcess.h"
#include<string>

class TipLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(TipLayer)
public:
	static TipLayer* createWithTipText(const std::string& tiptext);

	bool init(const std::string& tiptext);
private:

};

#endif // !__TIP_LAYER_H__


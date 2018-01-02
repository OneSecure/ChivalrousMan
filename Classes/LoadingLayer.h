#pragma once
#ifndef __LOADING_LAYER_H__
#define __LOADING_LAYER_H__
#include"PreProcess.h"
#include<string>

/*
*class LoadingLayer
*缓冲层，用户显示过渡动画
*/
class LoadingLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(LoadingLayer)
public:
	static LoadingLayer* create(const std::string& tip, const std::string& progressname);
	
	bool init(const std::string& tip, const std::string& progressname);

	std::string m_tipText;
};

#endif // !__LOADING_LAYER_H__
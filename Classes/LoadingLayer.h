#pragma once
#ifndef __LOADING_LAYER_H__
#define __LOADING_LAYER_H__
#include"PreProcess.h"
#include<string>

/*
*class LoadingLayer
*����㣬�û���ʾ���ɶ���
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
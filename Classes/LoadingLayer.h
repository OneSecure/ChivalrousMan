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
	/*
	*创建加载缓冲层
	*@param tip：缓冲层文字
	*@progressname ：进度条名称
	*@param haveBg：是否需要背景
	*/
	static LoadingLayer* create(const std::string& tip, const std::string& progressname,bool haveBg=true);
	
	bool init(const std::string& tip, const std::string& progressname,bool haveBg);

	std::string m_tipText;
};

#endif // !__LOADING_LAYER_H__
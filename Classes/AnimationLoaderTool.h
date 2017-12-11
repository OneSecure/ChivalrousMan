#pragma once
#ifndef __ANIMATION_LOADER_H__
#define __ANIMATION_LOADER_H__
#include"PreProcess.h"
#include<string>

/*
*AnimationLoader
*动画加载器
*/
class AnimationLoaderTool
{
public:
	/*
	*loadAnimationFromMinFile(const std::string& name, int num,float delay);
	*从单个小文件中加载动画
	*@param name:动画路径名称
	*@param num:单个小文件数量
	*@param delay：动画帧的延迟
	*@return Animation*:加载完成的动画
	*/
	static cocos2d::Animation* loadAnimationFromMinFile(const std::string& name, int num, float delay);

	/*
	*loadAnimationFromLargeFile(const std::string& name, int row, int rank);
	*从一整张大文件中加载动画
	*@param name:动画路径名
	*@param row:动画行数
	*@param rank：动画列数
	*@param delay：动画每帧的延迟
	*@return Animation*:加载完成的动画
	*/
	static cocos2d::Animation* loadAnimationFromLargeFile(const std::string& name, int row, int rank, float delay);
private:
	AnimationLoaderTool() {};
	~AnimationLoaderTool() {};
	
	static AnimationLoaderTool* m_instance;
}

#endif // !__ANIMATION_LOADER_H__
#pragma once
#ifndef __ANIMATION_LOADER_H__
#define __ANIMATION_LOADER_H__
#include"PreProcess.h"
#include<string>

/*
*AnimationLoader
*����������
*/
class AnimationLoaderTool
{
public:
	/*
	*loadAnimationFromMinFile(const std::string& name, int num,float delay);
	*�ӵ���С�ļ��м��ض���
	*@param name:����·������
	*@param num:����С�ļ�����
	*@param delay������֡���ӳ�
	*@return Animation*:������ɵĶ���
	*/
	static cocos2d::Animation* loadAnimationFromMinFile(const std::string& name, int num, float delay);

	/*
	*loadAnimationFromLargeFile(const std::string& name, int row, int rank);
	*��һ���Ŵ��ļ��м��ض���
	*@param name:����·����
	*@param row:��������
	*@param rank����������
	*@param delay������ÿ֡���ӳ�
	*@return Animation*:������ɵĶ���
	*/
	static cocos2d::Animation* loadAnimationFromLargeFile(const std::string& name, int row, int rank, float delay);
private:
	AnimationLoaderTool() {};
	~AnimationLoaderTool() {};
	
	static AnimationLoaderTool* m_instance;
}

#endif // !__ANIMATION_LOADER_H__
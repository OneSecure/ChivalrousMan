#pragma once
#ifndef __BEGIN_SCENE_H__
#define __BEGIN_SCENE_H__
#include"PreProcess.h"

/*
*class BeginScene
*��Ϸ�ս���ʱ����ĳ���
*/
class BeginScene:public cocos2d::Scene
{
	CLASS_ESSENTAIL(BeginScene)
	CREATE_FUNC(BeginScene)
public:
	virtual bool init();
};

#endif // !__BEGIN_SCENE_H__
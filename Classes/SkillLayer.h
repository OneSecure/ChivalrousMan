#pragma once
#ifndef __SKILL_LAYER_H__
#define __SKILL_LAYER_H__
#include"PreProcess.h"

/**
*class SkillLayer
*��ʾ��Ҽ���
*/
class SkillLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(SkillLayer)
	CREATE_FUNC(SkillLayer)
public:
 	virtual bool init() override;

private:

};

#endif // !__SKILL_LAYER_H__


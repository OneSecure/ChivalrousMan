#pragma once
#ifndef __CRACKIT_H__
#define __CRACKIT_H__
#include"PreProcess.h"
#include"RealSkill.h"
#include<string>

/*
*class CrackIt
*技能紫炎狼爪
*/
class CrackIt Inherit(RealSkill)
{
	CLASS_ESSENTAIL(CrackIt)
	SKILL__FUNC(CrackIt)
private:
	/*
	*造成伤害时间
	*/
	 void heart(float dt);
};

#endif // !__CRACKIT_H__


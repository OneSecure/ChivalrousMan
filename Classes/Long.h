#pragma once
#ifndef __LONG_H__
#define __LONG_H__
#include"PreProcess.h"
#include"RealSkill.h"

class Long Inherit(RealSkill)
{
	CLASS_ESSENTAIL(Long)
	SKILL__FUNC(Long)
private:
	void heart(float dt);
};


#endif // !__LONG_H__


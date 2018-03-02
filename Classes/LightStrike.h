#pragma once
#ifndef __LIGHTSTRIKE_H__
#define __LIGHTSTRIKE_H__
#include"PreProcess.h"
#include"RealSkill.h"

class LightStrike Inherit(RealSkill)
{
	CLASS_ESSENTAIL(LightStrike)
	SKILL__FUNC(LightStrike)
private:
	void heart(float dt);
};

#endif // !__LIGHTSTRIKE_H__



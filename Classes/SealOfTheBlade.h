#pragma once
#ifndef __SEALOFTHEBALDE_H__
#define __SEALOFTHEBALDE_H__
#include"PreProcess.h"
#include"RealSkill.h"

class SealOfTheBlade Inherit(RealSkill)
{
	CLASS_ESSENTAIL(SealOfTheBlade)
	SKILL__FUNC(SealOfTheBlade)
private:
	void heart(float dt);
};

#endif

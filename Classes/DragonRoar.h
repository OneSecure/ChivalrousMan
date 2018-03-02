#pragma once
#ifndef __DRAGONROAR_H__
#define __DRAGONROAR_H__
#include"PreProcess.h"
#include"RealSkill.h"

class DragonRoar Inherit(RealSkill)
{
	CLASS_ESSENTAIL(DragonRoar)
	SKILL__FUNC(DragonRoar)

private:
	void heart(float dt);
};

#endif // !


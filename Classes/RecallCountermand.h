#pragma once
#ifndef __RECALLCOUNTERMAND_H__
#define __RECALLCOUNTERMAND_H__
#include"PreProcess.h"
#include"RealSkill.h"

class RecallCounterMand Inherit(RealSkill)
{
	CLASS_ESSENTAIL(RecallCounterMand)
	SKILL__FUNC(RecallCounterMand)
private:
	void heart(float dt);
};

#endif // !__RECALLCOUNTERMAND_H__


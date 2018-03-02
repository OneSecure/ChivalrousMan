#pragma once
#ifndef __XBARROW_H__
#define __XBARROW_H__
#include"PreProcess.h"
#include"RealSkill.h"
 
class XBArrow Inherit(RealSkill)
{
	CLASS_ESSENTAIL(XBArrow)
	SKILL__FUNC(XBArrow)

private:
	void heart(float dt);
};

#endif // !__XBARROW_H__


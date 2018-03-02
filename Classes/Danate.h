#pragma once
#ifndef __DANATE_H__
#define __DANATE_H__
#include"PreProcess.h"
#include"RealSkill.h"

/*
*class Dante
*¼¼ÄÜÁÑµØ
*/
class Dante  Inherit(RealSkill)
{
public:
	Dante();
	virtual ~Dante();
	SKILL__FUNC(Dante)

private:
	void heart(float dt);
};

#endif // !__DANATE_H__


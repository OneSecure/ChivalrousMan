#pragma once
#ifndef __CRACKIT_H__
#define __CRACKIT_H__
#include"PreProcess.h"
#include"RealSkill.h"
#include<string>

/*
*class CrackIt
*����������צ
*/
class CrackIt Inherit(RealSkill)
{
	CLASS_ESSENTAIL(CrackIt)
	SKILL__FUNC(CrackIt)
private:
	/*
	*����˺�ʱ��
	*/
	 void heart(float dt);
};

#endif // !__CRACKIT_H__


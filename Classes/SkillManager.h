#pragma once
#ifndef __SKILL_MANAGER_H__
#define __SKILL_MANAGER_H__
#include"PreProcess.h"
#include<thread>
#include<atomic>
#include<mutex>

/*
*class SkillManager
*技能管理器
*/
class SkillManager
{
	GET_SINGLE_OBJECT(SkillManager)
public:
	static void release();

private:
	SkillManager();
	~SkillManager();

	SINGLE_ATTRIBUTES(SkillManager);
};

#endif // !__SKILL_MANAGER_H__

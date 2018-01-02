#pragma once
#ifndef  __SKILL_H__
#define  __SKILL_H__
#include"Thing.h"

class Skill Inherit(Thing)
{
public:
	Skill(const std::string& name);
	virtual ~Skill();

private:
	
};

#endif // ! __SKILL_H__


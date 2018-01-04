#pragma once
#ifndef  __SKILL_H__
#define  __SKILL_H__
#include"Thing.h"

class Skill Inherit(Thing)
{
public:
	static Skill* createWithImage(const std::string& filename);
	
	bool init(const std::string& filename);

	Skill(const std::string& name);
	virtual ~Skill();
private:
	void initProperty(const std::string& name);

};

#endif // ! __SKILL_H__
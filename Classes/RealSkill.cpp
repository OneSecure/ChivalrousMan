#include"RealSkill.h"
#include"Commen.h"

RealSkill::RealSkill()
{
	
}

RealSkill::~RealSkill()
{
	
}

void RealSkill::died(float dt)
{
	m_parent->removeChild(this);
}
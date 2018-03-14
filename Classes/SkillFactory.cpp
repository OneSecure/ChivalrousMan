#include"SkillFactory.h"
#include"Commen.h"
#include"CrackIt.h"
#include"Danate.h"
#include"DragonRoar.h"
#include"LightStrike.h"
#include"Long.h"
#include"RecallCountermand.h"
#include"SealOfTheBlade.h"
#include"XBArrow.h"

RealSkill* SkillFactory::createSkill(std::string name, cocos2d::Layer* parent,cocos2d::CCObject* towho, const float& attack)
{
	if (name == "CrackIt")
	{
		return CrackIt::create(parent,towho, attack);
	}
	else if (name=="Dante")
	{
		return Dante::create(parent, towho, attack);
	}
	else if (name == "DragonRoar")
	{
		return DragonRoar::create(parent, towho, attack);
	}
	else if (name == "LightStrike")
	{
		return  LightStrike::create(parent, towho, attack);
	}
	else if (name == "Long")
	{
		return Long::create(parent, towho, attack);
	}
	else if (name == "RecallCountermand")
	{
		return RecallCounterMand::create(parent, towho, attack);
	}
	else if (name == "SealOfTheBlade")
	{
		return SealOfTheBlade::create(parent, towho, attack);
	}
	else if (name == "XBArrow")
	{
		return XBArrow::create(parent, towho, attack);
	}
	else
	{
		return nullptr;
	}
}
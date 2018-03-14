#include"SealOfTheBlade.h"
#include"Commen.h"
#include"FightLayer.h"
#include"Monster.h"

bool SealOfTheBlade::init(Layer* parent,cocos2d::CCObject* towho, const float& baseattack)
{
	if (RealSkill::init())
	{
		auto size = SCREEN;
		m_parent = parent;
		m_baseattack = baseattack;
		m_towho = towho;
		this->setPosition(220, size.height*0.52);
		m_parent->addChild(this);

		//LoadAnimationFromMinFile(, 15, 0.1, animation);
		Animate* animate = Animate::create(getAnimation("Skill/SealOfTheBlade/SealOfTheBlade"));
		this->runAction(animate);

		scheduleOnce(schedule_selector(SealOfTheBlade::died), 1.5);
		scheduleOnce(schedule_selector(SealOfTheBlade::heart), 0.7);
		this->setTag(1.5);    //使用tag标记技能持续时间
		return true;
	}
	return false;
}

void SealOfTheBlade::heart(float dt)
{
	FightLayer* pFt = dynamic_cast<FightLayer*>(m_parent);
	for (auto var : pFt->m_monsterList)
	{
		var->beAttack(m_baseattack);
	}
}
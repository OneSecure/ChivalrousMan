#include"CrackIt.h"
#include"Commen.h"
#include"FightLayer.h"
#include"Monster.h"
#include"GameData.h"

bool CrackIt::init(cocos2d::Layer* parent,cocos2d::CCObject* towho, const float& baseattack)
{
	if (RealSkill::init())
	{
		auto size = SCREEN;
		m_parent = parent;
		m_baseattack = baseattack;
		m_towho = towho;
		setPosition(size.width*0.2, size.height*0.45);
		m_parent->addChild(this);

		//LoadAnimationFromMinFile(, 16, 0.15, animation);
		Animate* animate = Animate::create(getAnimation("Skill/CrackIt/CrackIt"));
		this->runAction(animate);

		scheduleOnce(schedule_selector(CrackIt::died), 2.5);
		scheduleOnce(schedule_selector(CrackIt::heart), 1.2);
		this->setTag(2.5);    //使用tag标记技能持续时间
		return true;
	}
	return false;
}

void CrackIt::heart(float dt)
{
	FightLayer* pFt = dynamic_cast<FightLayer*>(m_parent);
	for (auto var : pFt->m_monsterList)
	{
		var->beAttack(m_baseattack);
	}
}
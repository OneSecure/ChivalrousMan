#include"Long.h"
#include"Commen.h"
#include"FightLayer.h"
#include"Monster.h"

bool Long::init(Layer* parent, const float& baseattack)
{
	if (RealSkill::init())
	{
		m_parent = parent;
		m_baseattack = baseattack;
		FightLayer* pFt = dynamic_cast<FightLayer*>(m_parent);
		Vec2 pos = pFt->m_selectedMonster->getPosition();
		this->setPosition(pos.x+30, pos.y);
		m_parent->addChild(this);

		Animation* animation;
		LoadAnimationFromMinFile("Skill/Long/Long", 10, 0.15, animation);
		Animate* animate = Animate::create(animation);
		this->runAction(animate);

		scheduleOnce(schedule_selector(Long::died), 1.5);
		scheduleOnce(schedule_selector(Long::heart), 0.9);
		this->setTag(1.5);    //使用tag标记技能持续时间
		return true;
	}
	return false;
}

void Long::heart(float dt)
{
	dynamic_cast<FightLayer*>(m_parent)->m_selectedMonster->beAttack(m_baseattack);
}
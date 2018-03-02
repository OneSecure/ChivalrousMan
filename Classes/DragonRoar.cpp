#include"DragonRoar.h"
#include"Commen.h"
#include"CameraPlayer.h"
#include"FightLayer.h"
#include"GameData.h"
#include"Monster.h"

bool DragonRoar::init(cocos2d::Layer* parent, const float& baseattack)
{
	if (RealSkill::init())
	{
		m_parent = parent;
		m_baseattack = baseattack;
		FightLayer* pFt = dynamic_cast<FightLayer*>(m_parent);
		Vec2 pos = pFt->m_selectedMonster->getPosition();
		this->setPosition(pos.x + 90, pos.y);
		m_parent->addChild(this);
	
		Animation* animation;
		LoadAnimationFromMinFile("Skill/DragonRoar/DragonRoar", 9, 0.15, animation);
		Animate* animate = Animate::create(animation);
		this->runAction(animate);

		scheduleOnce(schedule_selector(DragonRoar::died), 1.35);
		scheduleOnce(schedule_selector(DragonRoar::heart), 0.8);
		setTag(1.35);
		return true;
	}
	return false;
}

void DragonRoar::heart(float dt)
{
	dynamic_cast<FightLayer*>(m_parent)->m_selectedMonster->beAttack(m_baseattack);
}
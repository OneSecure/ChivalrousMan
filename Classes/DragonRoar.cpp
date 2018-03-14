#include"DragonRoar.h"
#include"Commen.h"
#include"CameraPlayer.h"
#include"FightLayer.h"
#include"GameData.h"
#include"Monster.h"

bool DragonRoar::init(cocos2d::Layer* parent,cocos2d::CCObject* towho, const float& baseattack)
{
	if (RealSkill::init())
	{
		m_parent = parent;
		m_baseattack = baseattack;
		m_towho = m_towho;
		Vec2 pos = ((Monster*)m_towho)->getPosition();
		this->setPosition(pos.x + 90, pos.y);
		m_parent->addChild(this);
	
		//LoadAnimationFromMinFile(, 9, 0.15, animation);
		Animate* animate = Animate::create(getAnimation("Skill/DragonRoar/DragonRoar"));
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
	dynamic_cast<Monster*>(m_towho)->beAttack(m_baseattack);
}
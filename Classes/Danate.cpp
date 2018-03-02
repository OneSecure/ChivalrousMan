#include"Danate.h"
#include"FightLayer.h"
#include"CameraPlayer.h"
#include"GameData.h"
#include"Monster.h"
#include"Commen.h"

Dante::Dante()
{

}

Dante::~Dante()
{
	
}


bool Dante::init(cocos2d::Layer* parent, const float& baseattack)
{
	if (RealSkill::init())
	{
		m_parent = parent;
		m_baseattack = baseattack;
		FightLayer* pFt = dynamic_cast<FightLayer*>(parent);
		Vec2 pos=pFt->m_selectedMonster->getPosition();
		setPosition(pos.x+10, pos.y);
		m_parent->addChild(this);
		
		Animation* animation;
		LoadAnimationFromMinFile("Skill/Dante/Dante", 14, 0.15, animation);
		Animate* animate = Animate::create(animation);
		this->runAction(animate);

		scheduleOnce(schedule_selector(Dante::died), 2.6);
		scheduleOnce(schedule_selector(Dante::heart), 1.3);
		setTag(2.6);   //使用tag标记技能持续时间
		return true;
	}
	return false;
}

void Dante::heart(float dt)
{
	dynamic_cast<FightLayer*>(m_parent)->m_selectedMonster->beAttack(m_baseattack);
}
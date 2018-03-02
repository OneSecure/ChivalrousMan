#include"XBArrow.h"
#include"Commen.h"
#include"FightLayer.h"
#include"Monster.h"

bool XBArrow::init(Layer* parent, const float& baseattack)
{
	if (RealSkill::init())
	{
		m_parent = parent;
		m_baseattack = baseattack;
		FightLayer* pFt = dynamic_cast<FightLayer*>(m_parent);
		Vec2 pos = pFt->m_selectedMonster->getPosition();
		this->setPosition(200, pos.y + 20);
		m_parent->addChild(this);

		Animation* animation;
		LoadAnimationFromMinFile("Skill/XBArrow/XBArrow",9, 0.15, animation);
		Animate* animate = Animate::create(animation);
		this->runAction(animate);

		scheduleOnce(schedule_selector(XBArrow::died), 1.35);
		scheduleOnce(schedule_selector(XBArrow::heart), 0.8);
		this->setTag(1.35);    //使用tag标记技能持续时间
		return true;
	}
	return false;
}

void XBArrow::heart(float dt)
{
	FightLayer* pFt = dynamic_cast<FightLayer*>(m_parent);
	size_t size = pFt->m_monsterList.size();
	for (size_t i = 0; i < size; ++i)
	{
		if (pFt->m_monsterList[i] == pFt->m_selectedMonster)
		{
			if (i % 2 == 1)
			{
				pFt->m_monsterList[i]->beAttack(m_baseattack);
				pFt->m_monsterList[i - 1]->beAttack(m_baseattack);
			}
			else
			{
				pFt->m_monsterList[i]->beAttack(m_baseattack);
				if (i + 1 < size)
					pFt->m_monsterList[i + 1]->beAttack(m_baseattack);
			}
		}
	}
}
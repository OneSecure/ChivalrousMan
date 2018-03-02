#include"Monster.h"
#include"Commen.h"
#include"GameData.h"
#include"HurtValueLayer.h"
#include"FightLayer.h"
#include"TaskSystem.h"
#include<fstream>
   
Monster::Monster(const std::string& name)
{
	initProperty(name);
}

Monster::~Monster()
{

}

 Monster* Monster::createWithName(const std::string& name)
{
	 Monster* pRet = new Monster(StringValue(name));
	 if (pRet&&pRet->init(StringValue(name)))
	 {
		 pRet->m_name = name;
		 pRet->autorelease();
		 return pRet;
	 }
	 else
	 {
		 delete pRet;
		 pRet = nullptr;
		 return nullptr;
	 }
}

bool Monster::init(const std::string& name)
{
	if (Sprite::init())
	{
		initMonsterAnimation(name, m_frames);
		return true;
	}
	return false;
}


void Monster::initProperty(const std::string& name)
{
	std::string realname = name;
	realname += ".att";
	std::ifstream fin;
	fin.open(realname, std::ios::in);
	if (fin.fail())
	{
		return;
	}
	std::string tmp;
	fin >> tmp;
	fin >> m_name;

	ADD_PROPERTY(attack);
	ADD_PROPERTY(blood);
	ADD_PROPERTY(defense);
	ADD_PROPERTY(speed);
	ADD_PROPERTY(exp);
	ADD_PROPERTY(glod);
	ADD_PROPERTY(frames);
	fin.close();
}

void Monster::initMonsterAnimation(const std::string& name, int num)
{
	Animation* animation;
	LoadAnimationFromMinFile(name.c_str(), num, 0.15, animation);
	auto animate = Animate::create(animation);
	this->runAction(CCRepeatForever::create(animate));
}

int Monster::beAttack(float attack)
{
	if (m_isdie)
	{
		return -1;
	}
	auto move1 = MoveBy::create(0.2, ccp(-35, 0));
	auto move2 = MoveBy::create(0.2, ccp(35, 0));
	this->runAction(Sequence::createWithTwoActions(move1, move2));
	float hurtvalue = attack <= m_defense ? 1 : attack - m_defense;
	Vec2 pos = getPosition();
	pos.y += 90;
	auto hurtlayer = HurtsValueLayer::createWithInfo(pos, hurtvalue);
	getParent()->addChild(hurtlayer);
	this->m_blood -= hurtvalue;
	if (m_blood <= 0)
	{
		m_isdie = true;
		dynamic_cast<FightLayer*>(getParent())->removeMonster(this);
		TaskSystem::getInstance()->checkKillMonster(m_name);
		return -1;
	}
	return 0;
}

bool Monster::isDie()
{
	return m_isdie;
}
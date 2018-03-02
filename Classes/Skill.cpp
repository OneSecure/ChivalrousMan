#include"Skill.h"
#include"Commen.h"
#include"FightLayer.h"
#include"SkillFactory.h"
#include"CameraPlayer.h"
#include"TipLayer.h"
#include"GameData.h"
#include<fstream>

#define NoMana()  \
TipLayer* tiplayer = TipLayer::createTipLayer(StringValue("NoMana"));   \
pFt->addChild(tiplayer)

Skill::Skill(const std::string& name):
	Thing(name)
{
	initProperty(name);
	m_grade = 1;
}

Skill::~Skill()
{

}

Skill* Skill::createWithImage(const std::string& filename)
{
	Skill* pRet = new Skill(getfileName(filename));
	if (pRet&&pRet->init(filename))
	{
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

bool Skill::init(const std::string& filename)
{
	if (Thing::init())
	{
		Sprite* face = Sprite::create(filename);
		this->setNormalImage(face);
		this->setSelectedImage(face);

		return true;
	}
	return false;
}

void Skill::initProperty(const std::string& name)
{
	std::string realname = name;
	realname += ".att";
	std::fstream fin;
	fin.open(realname, std::ios::in);
	if (fin.fail())
	{
		return;
	}
	std::string tmp;
	fin >> m_name;
	fin >> m_name;
	fin >> m_name;
	ADD_PROPERTY(buyglod);
	ADD_PROPERTY(sellglod);
	ADD_PROPERTY(baseAttack);
	ADD_PROPERTY(baseMana);
	ADD_PROPERTY(baseupGlod);
	fin.close();
}

float Skill::beUse(cocos2d::CCObject* obj)
{
	FightLayer* pFt = dynamic_cast<FightLayer*>(obj);
	if (GetPlayerData().getcurmana() >= m_baseMana)
	{
		RealSkill* skill = SkillFactory::createSkill(m_name, pFt, m_baseAttack + 30 * m_grade);
		auto move1 = MoveBy::create(0.2, ccp(-20, 0));
		auto move2 = MoveBy::create(0.2, ccp(20, 0));
		pFt->m_player->runAction(Sequence::createWithTwoActions(move1, move2));
		GetPlayerData().subcurMana(m_baseMana + 10 * m_grade);
		return skill->getTag();
	}
	else
	{
		NoMana();
		pFt->playerAttackMonster();
		return -1.0;
	}
}

void Skill::incGrade()
{
	++m_grade;
}
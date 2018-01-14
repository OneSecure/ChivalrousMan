#include"Monster.h"
#include"Commen.h"
#include"GameData.h"
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

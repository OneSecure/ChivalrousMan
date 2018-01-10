#include"Monster.h"
#include"Commen.h"
#include<fstream>
   
Monster::Monster(const std::string name)
{
	initProperty(name);
}

Monster::~Monster()
{

}

void Monster::initProperty(const std::string& name)
{
	std::ifstream fin;
	fin.open(name, std::ios::in);
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
	fin >> tmp;
	fin >> tmp;
	initFaceWithFrames(name, std::stoi(tmp));
	fin.close();
}

void Monster::initFaceWithFrames(const std::string& name, int num)
{
	m_face = Sprite::create();
	Animation* animation;
	LoadAnimationFromMinFile(name, num, 0.35, animation);
	auto animate = Animate::create(animation);
	m_face->runAction(CCRepeatForever::create(animate));
	CC_SAFE_RETAIN(m_face);
}

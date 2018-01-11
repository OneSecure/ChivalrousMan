#include"Skill.h"
#include"Commen.h"
#include<fstream>

Skill::Skill(const std::string& name):
	Thing(name)
{
	initProperty(name);
}
 
Skill::~Skill()
{

}

Skill* Skill::createWithImage(const std::string& filename)
{
	Skill* pRet = new Skill(getName(filename));
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
	ADD_PROPERTY(buyglod);
	ADD_PROPERTY(sellglod);
	fin.close();
}
#include"Skill.h"
#include"Commen.h"

Skill::Skill(const std::string& name):
	Thing(name)
{

}
 
Skill::~Skill()
{

}

Skill* Skill::createWithImage(const std::string& filename)
{
	Skill* pRet = new Skill(filename);
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
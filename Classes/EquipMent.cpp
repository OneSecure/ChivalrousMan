#include"EquipMent.h"
#include"Commen.h"
#include<fstream>
 
EquipMent::EquipMent(const std::string& name):
	Thing(name)
{
	initProperty(name);
}

EquipMent::~EquipMent()
{

}

EquipMent* EquipMent::createWithImage(const std::string& filename)
{
	EquipMent* pRet = new EquipMent(getName(filename));
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

bool  EquipMent::init(const std::string& filename)
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

void EquipMent::initProperty(const std::string& name)
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
	ADD_PROPERTY(buyglod);
	ADD_PROPERTY(sellglod);
	ADD_PROPERTY(addblood);
	ADD_PROPERTY(addmana);
	ADD_PROPERTY(addattack);
	ADD_PROPERTY(adddefense);
	ADD_PROPERTY(addspeed);
	fin.close();
}
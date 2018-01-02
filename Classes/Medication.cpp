#include"Medication.h"
#include"Commen.h"
#include<fstream>

Medication::Medication(const std::string& name):
	Thing(name)
{
	initProperty(name);
}

Medication::~Medication()
{

}

Medication* Medication::createWithImage(const std::string& filename)
{
	Medication* pRet = new Medication(getName(filename));
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

bool Medication::init(const std::string& filename)
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

void Medication::initProperty(const std::string& name)
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
	fin.close();
}
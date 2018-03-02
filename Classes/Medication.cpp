#include"Medication.h"
#include"Commen.h"
#include"CameraPlayer.h"
#include"TipLayer.h"
#include"GameData.h"
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
	Medication* pRet = new Medication(getfileName(filename));
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
	ADD_PROPERTY(addblood);
	ADD_PROPERTY(addmana);
	fin.close();
}

float Medication::beUse(cocos2d::CCObject* obj)
{
	GetPlayerData().addcurBlood(m_addblood);
	GetPlayerData().addcurMana(m_addmana);
	std::string tiptext = "";
	tiptext += StringValue("Blood") + NumberToString(m_addblood) 
		+ " " + StringValue("Mana") + "+" + 
		NumberToString(m_addmana);
	TipLayer* tipLayer = TipLayer::createTipLayer(tiptext);
	dynamic_cast<Layer*>(obj)->addChild(tipLayer);
	return 0.0f;
}
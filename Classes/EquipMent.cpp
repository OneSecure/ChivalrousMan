#include"EquipMent.h"
#include"Commen.h"
#include"CameraPlayer.h"
#include"GameData.h"
#include"BackPackManager.h"
#include"EquipmentManager.h"
#include"TipLayer.h"
#include"GameData.h"
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
	EquipMent* pRet = new EquipMent(getfileName(filename));
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
		m_baseupglod = m_addblood + m_addmana + m_addattack * 10 + m_adddefense * 10;
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
	ADD_PROPERTY(type);
	fin.close();
}

float EquipMent::beUse(cocos2d::CCObject* obj,cocos2d::CCObject* who,cocos2d::CCObject* towho)
{
	EMInfo info;
	info.name = m_name;
	info.type = m_type;
	info.grade = m_grade;
	EquipmentManager::getInstance()->wearEquipment(info);
	GetPlayerData().addProperty(m_addblood+ (m_grade - 1) *30, m_addmana+ (m_grade - 1) *30, m_addattack+ (m_grade - 1) *8, m_adddefense+(m_grade-1)*8);
	TipLayer* tiplayer = TipLayer::createTipLayer(StringValue("WearSuccess"));
	dynamic_cast<Layer*>(obj)->addChild(tiplayer);
	return 0;
}

int  EquipMent::Disassemble(Node* node)
{
	if (node != nullptr)
		node->removeChildByName("PropertyLayer");
	float subblood = m_addblood + (m_grade-1) * 30;
	float submana = m_addmana + (m_grade - 1) * 30;
	float subattack = m_addattack + (m_grade - 1) * 8;
	float subdefense = m_adddefense + (m_grade - 1) * 8;
	GetPlayerData().addProperty(-subblood, -submana, -subattack, -subdefense);
	ThingInfo info;
	info.name = m_name;
	info.nums = 1;
	info.type = EQUIPMENT;
	info.grade = m_grade;
	BackPackManager::getInstance()->addBackPackThing(info);
	return 0;
}

void EquipMent::upgrade(Node* node)
{
	auto obj = node->getChildByName("PropertyLayer");
	m_grade += 1;
	GetPlayerData().addProperty(30, 30, 8, 8);
	if (obj != nullptr)
	{
		showProperty(node);
	}
}

void EquipMent::showProperty(cocos2d::Node* node)
{
	auto size = SCREEN;
	node->removeChildByName("PropertyLayer");
	Layer* layer = Layer::create();
	layer->setName("PropertyLayer");
	node->addChild(layer);
	auto  bg = Sprite::create(StringValue("DetailBg"));
	bg->setPosition(bg->getContentSize().width*0.5 + 10, size.height*0.5);
	layer->addChild(bg);
	auto labelname = LabelTTF::create(m_firsttext, "楷体", 20);
	labelname->setPosition(bg->getPositionX(), bg->getPositionY() + bg->getContentSize().height*0.5 - 60);
	layer->addChild(labelname);
	auto labelblood = LabelTTF::create(StringValue("Blood") + ":" + NumberToString(m_addblood + (m_grade - 1) * 30),
		"楷体", 20);
	labelblood->setPosition(bg->getPositionX(), labelname->getPositionY() - 30);
	layer->addChild(labelblood);
	auto labelmana = LabelTTF::create(StringValue("Mana") + ":" + NumberToString(m_addmana + (m_grade - 1) * 30),
		"楷体", 20);
	labelmana->setPosition(bg->getPositionX(), labelblood->getPositionY() - 30);
	layer->addChild(labelmana);
	auto labelattack = LabelTTF::create(StringValue("Attack") + ":" + NumberToString(m_addattack + (m_grade - 1) * 8),
		"楷体", 20);
	labelattack->setPosition(bg->getPositionX(), labelmana->getPositionY() - 30);
	layer->addChild(labelattack);
	auto labeldefense = LabelTTF::create(StringValue("Defense") + ":" + NumberToString(m_adddefense + (m_grade - 1) * 8),
		"楷体", 20);
	labeldefense->setPosition(bg->getPositionX(), labelattack->getPositionY() - 30);
	layer->addChild(labeldefense);
	auto labelgrade = LabelTTF::create(StringValue("GradeText") + NumberToString(m_grade),
		"楷体", 20);
	labelgrade->setPosition(bg->getPositionX(), labeldefense->getPositionY() - 30);
	layer->addChild(labelgrade);
	auto upglodlabel = LabelTTF::create(StringValue("NextGrade") + ":" + NumberToString(m_baseupglod + m_grade*(100 + m_baseupglod / 10)),
		"楷体", 20);
	upglodlabel->setPosition(bg->getPositionX(), labelgrade->getPositionY() - 30);
	upglodlabel->setColor(Color3B::YELLOW);
	layer->addChild(upglodlabel);
}

float EquipMent::upGlod()
{
	return m_baseupglod + m_grade*(100 + m_baseupglod / 10);
}
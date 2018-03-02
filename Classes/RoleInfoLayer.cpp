#include"RoleInfoLayer.h"
#include"Commen.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"CameraPlayer.h"
#include"EquipmentManager.h"
#include"EquipMent.h"
#include"TipLayer.h"
#include<string>

bool RoleInfoLayer::init()
{
	if (Layer::init())
	{
		auto size = SCREEN;
		auto bg = Sprite::create(StringValue("RoleBg"));
		bg->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(bg);
		auto line = Sprite::create(StringValue("Line"));
		line->setPosition(size.width*0.60, size.height*0.5);
		this->addChild(line);
		Vec2 basePos = bg->getPosition();
		basePos.x -= bg->getContentSize().width*0.5;
		basePos.y += bg->getContentSize().height*0.5;

		auto equipmentbg = Sprite::create(StringValue("EquipmentGrid"));
		equipmentbg->setPosition(bg->getPositionX() - 100, bg->getPositionY()-25);
		this->addChild(equipmentbg);
		m_centerP = equipmentbg->getPosition();
		
		auto bloodlabel = LabelTTF::create(StringValue("Blood") + ":", "楷体", 25);
		bloodlabel->setPosition(basePos.x + 50, basePos.y - 30);
		bloodlabel->setColor(Color3B::RED);
		this->addChild(bloodlabel);
		auto manalabel = LabelTTF::create(StringValue("Mana") + ":", "楷体", 25);
		manalabel->setPosition(basePos.x + 50, basePos.y - 60);
		manalabel->setColor(Color3B::GREEN);
		this->addChild(manalabel);
		auto explabel = LabelTTF::create(StringValue("Exp") + ":", "楷体", 25);
		explabel->setPosition(basePos.x + 50, basePos.y - 90);
		explabel->setColor(ccc3(255, 127, 39));
		this->addChild(explabel);

		auto bloodBg = Sprite::create(StringValue("BarBg"));
		bloodBg->setPosition(bloodlabel->getPositionX() + 110, bloodlabel->getPositionY());
		this->addChild(bloodBg);
		auto manaBg = Sprite::create(StringValue("BarBg"));
		manaBg->setPosition(manalabel->getPositionX() + 110, manalabel->getPositionY());
		this->addChild(manaBg);
		auto expBg = Sprite::create(StringValue("BarBg"));
		expBg->setPosition(explabel->getPositionX() + 110, explabel->getPositionY());
		this->addChild(expBg);
		auto bloodBar = Sprite::create(StringValue("BloodBar"));
		m_bloodBar = ProgressTimer::create(bloodBar);
		m_bloodBar->setType(ProgressTimer::Type::BAR);
		m_bloodBar->setMidpoint(ccp(0, 0));
		m_bloodBar->setBarChangeRate(ccp(1, 0));
		m_bloodBar->setPercentage(100);
		m_bloodBar->setPosition(bloodBg->getPosition());
		this->addChild(m_bloodBar);
		auto manaBar = Sprite::create(StringValue("ManaBar"));
		m_manaBar = ProgressTimer::create(manaBar);
		m_manaBar->setType(ProgressTimer::Type::BAR);
		m_manaBar->setMidpoint(ccp(0, 0));
		m_manaBar->setBarChangeRate(ccp(1, 0));
		m_manaBar->setPercentage(100);
		m_manaBar->setPosition(manaBg->getPosition());
		this->addChild(m_manaBar);
		auto expBar = Sprite::create(StringValue("ExpBar"));
		m_expBar = ProgressTimer::create(expBar);
		m_expBar->setType(ProgressTimer::Type::BAR);
		m_expBar->setMidpoint(ccp(0, 0));
		m_expBar->setBarChangeRate(ccp(1, 0));
		m_expBar->setPercentage((GetPlayerData().getexp() / GetPlayerData().getmaxExp()) * 100);
		m_expBar->setPosition(expBg->getPosition());
		this->addChild(m_expBar);
		
		bloodvalue = LabelTTF::create(NumberToString(GetPlayerData().getblood()) + "/" + NumberToString(GetPlayerData().getblood()),
			"楷体", 20);
		bloodvalue->setPosition(bloodBg->getPositionX() + 130, bloodBg->getPositionY());
		bloodvalue->setColor(Color3B::RED);
		this->addChild(bloodvalue);
		manavalue = LabelTTF::create(NumberToString(GetPlayerData().getmana()) + "/" + NumberToString(GetPlayerData().getmana()),
			"楷体", 20);
		manavalue->setPosition(manaBg->getPositionX() + 130, manaBg->getPositionY());
		manavalue->setColor(Color3B::GREEN);
		this->addChild(manavalue);
		auto expvalue = LabelTTF::create(NumberToString(GetPlayerData().getexp()) + "/" + NumberToString(GetPlayerData().getmaxExp()),
			"楷体", 20);
		expvalue->setPosition(expBg->getPositionX() + 130, expBg->getPositionY());
		expvalue->setColor(ccc3(255, 127, 39));
		this->addChild(expvalue);

		m_menu = Menu::create();
		m_menu->setPosition(0, 0);
		this->addChild(m_menu);
		auto upBtn = MenuItemImage::create(StringValue("BtnUp"), StringValue("BtnUp"),
			this, menu_selector(RoleInfoLayer::onUpBtnClick));
		upBtn->setPosition(equipmentbg->getPositionX(), equipmentbg->getPositionY() - 120);
		m_menu->addChild(upBtn);
		auto disassembelBtn = MenuItemImage::create(StringValue("Disassemble"), StringValue("Disassemble"),
			this, menu_selector(RoleInfoLayer::onDisassembleBtnClick));
		disassembelBtn->setPosition(upBtn->getPositionX(), upBtn->getPositionY() - 40);
		m_menu->addChild(disassembelBtn);

		auto namelabel = LabelTTF::create(GetStringData("rolename"), "楷体", 25);
		namelabel->setPosition(size.width*0.7, basePos.y - 25);
		this->addChild(namelabel);
		attacklabel = LabelTTF::create(StringValue("Attack") + ":" + NumberToString(GetPlayerData().getattack()),
			"楷体", 25);
		attacklabel->setPosition(size.width *0.7, basePos.y - 90);
		attacklabel->setColor(ccc3(255, 128, 0));
		this->addChild(attacklabel);
		defenselabel = LabelTTF::create(StringValue("Defense") + ":" + NumberToString(GetPlayerData().getdefense()),
			"楷体", 25);
		defenselabel->setPosition(size.width*0.7, basePos.y - 140);
		defenselabel->setColor(ccc3(128, 64, 0));
		this->addChild(defenselabel);
		auto gradelabel = LabelTTF::create(StringValue("GradeText") + NumberToString(GetPlayerData().getgrade()),
			"楷体", 25);
		gradelabel->setPosition(size.width*0.7, basePos.y - 190);
		gradelabel->setColor(ccc3(0, 255, 0));
		this->addChild(gradelabel);

		initRoleEquipment();

		m_selector = Sprite::create(StringValue("Selector"));
		this->addChild(m_selector);
		m_selector->setPosition(m_centerP);

		scheduleUpdate();
		
		return true;
	}
	return false;
}

void RoleInfoLayer::update(float dt)
{
	bloodvalue->setString(NumberToString(GetPlayerData().getblood()) + "/" + NumberToString(GetPlayerData().getblood()));
	manavalue->setString(NumberToString(GetPlayerData().getmana()) + "/" + NumberToString(GetPlayerData().getmana()));
	attacklabel->setString(StringValue("Attack") + ":" + NumberToString(GetPlayerData().getattack()));
	defenselabel->setString(StringValue("Defense") + ":" + NumberToString(GetPlayerData().getdefense()));
}

void RoleInfoLayer::onUpBtnClick(cocos2d::CCObject* sender)
{
	ClickAction(sender);
	if (m_curSel != nullptr)
	{
		float glod = dynamic_cast<EquipMent*>(m_curSel)->upGlod();
		if (GetPlayerData().getglod() >= glod)
		{
			std::string name = dynamic_cast<EquipMent*>(m_curSel)->getname();
			EquipmentManager::getInstance()->upEquipment(name);
			dynamic_cast<EquipMent*>(m_curSel)->upgrade(this);
			GetPlayerData().subGlod(glod);
		}
		else
		{
			TipLayer* tiplayer = TipLayer::createTipLayer(StringValue("LackGlod"));
			this->addChild(tiplayer);
		}
	}
}

void RoleInfoLayer::onEquipmentClickCallback(cocos2d::CCObject* sender)
{
	m_curSel = sender;
	Vec2 pos=dynamic_cast<EquipMent*>(sender)->getPosition();
	dynamic_cast<EquipMent*>(sender)->showProperty(this);
	auto move = MoveTo::create(0.2, pos);
	m_selector->runAction(move);
}

void RoleInfoLayer::initRoleEquipment()
{
	for (auto it = EquipmentManager::getInstance()->getEmList().begin();
		it != EquipmentManager::getInstance()->getEmList().end(); ++it)
	{
		auto eq = EquipMent::createWithImage(it->name + ".png");
		eq->setgrade(it->grade);
		eq->setTarget(this, menu_selector(RoleInfoLayer::onEquipmentClickCallback));
		switch (it->type)
		{
		case EM_HEAD:
			eq->setPosition(m_centerP.x, m_centerP.y + 55);
			break;
		case EM_WEPON:
			eq->setPosition(m_centerP.x - 55, m_centerP.y);
			break;
		case EM_JEWELRY:
			eq->setPosition(m_centerP.x + 55, m_centerP.y);
			break;
		case EM_CLOTH:
			eq->setPosition(m_centerP);
			break;
		case EM_FOOT:
			eq->setPosition(m_centerP.x, m_centerP.y - 55);
			break;
		default:
			break;
		}
		m_menu->addChild(eq);
	}
}

void RoleInfoLayer::onDisassembleBtnClick(cocos2d::CCObject* sender)
{
	ClickAction(sender);
	if (m_curSel!=nullptr)
	{
		std::string name = dynamic_cast<EquipMent*>(m_curSel)->getname();
		EquipmentManager::getInstance()->removeEquipment(name);
		dynamic_cast<EquipMent*>(m_curSel)->Disassemble(this);
		dynamic_cast<EquipMent*>(m_curSel)->setVisible(false);
		m_curSel = nullptr;
	}
}
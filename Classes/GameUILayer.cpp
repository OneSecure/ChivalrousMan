#include"GameUILayer.h"
#include"Commen.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"GameMenuLayer.h"
#include"SkillLayer.h"
#include"BackPackLayer.h"
#include"WorldMapLayer.h"
#include"GameScene.h"
#include"GameLogicLayer.h"
#include"CameraPlayer.h"

#define SHOW_AND_DELETE_LAYER(__LAYER__)  \
m_isclick##__LAYER__ = !m_isclick##__LAYER__;    \
if (m_isclick##__LAYER__)    \
{    \
	((GameScene*)getParent())->pauseAllActions(getParent(), this); \
	auto layer = __LAYER__::create();    \
	layer->setName(#__LAYER__);    \
	getParent()->addChild(layer);    \
}    \
else    \
{    \
	((GameScene*)getParent())->resumeAllActions(getParent()); \
	getParent()->removeChildByName(#__LAYER__);   } 

bool GameUILayer::init()
{
	if (Layer::init())
	{
		generateUserInterface();
		return true;
	}
	return false;
}

void GameUILayer::generateUserInterface()
{
	auto size = SCREEN;
	LISTEN_TOUCH(GameUILayer);

	auto menu = Menu::create();
	menu->setPosition(0, 0);
	this->addChild(menu);

	auto headFrame = Sprite::create(StringValue("HeadFrame"));
	headFrame->setPosition(headFrame->getContentSize().width*0.5 + 10, size.height - headFrame->getContentSize().height*0.5 - 15);
	this->addChild(headFrame);
	char headname[40] = { 0 };
	sprintf_s(headname, "%sHead", GetStringData("PlayerType").c_str());
	m_head = MenuItemImage::create(StringValue(headname),
		StringValue(headname), this,
		menu_selector(GameUILayer::onHeadClickCallBack));
	m_head->setPosition(headFrame->getPosition().x - 5, headFrame->getPosition().y + 5);
	menu->addChild(m_head);

	auto labelgrade = LabelTTF::create(StringValue("GradeText"), "楷体", 20);
	labelgrade->setColor(ccc3(0, 0, 0));
	labelgrade->setPosition(labelgrade->getContentSize().width*0.5 + 20, size.height - headFrame->getContentSize().height - 25);
	this->addChild(labelgrade);
	m_grade = LabelTTF::create(NumberToString(GetPlayerData().getgrade()), "楷体", 20);
	m_grade->setPosition(labelgrade->getPosition().x + labelgrade->getContentSize().width, labelgrade->getPosition().y);
	this->addChild(m_grade);
	
	m_roleName = LabelTTF::create(GetStringData("rolename"), "楷体", 20);
	m_roleName->setPosition(labelgrade->getPosition().x, labelgrade->getPosition().y - 20);
	this->addChild(m_roleName);

	m_backpack = MenuItemImage::create(StringValue("BackPack"), 
		StringValue("BackPack"),this,
		menu_selector(GameUILayer::onBackPackClickCallBack));
	m_backpack->setPosition(size.width - m_backpack->getContentSize().width*0.5 - 15, m_backpack->getContentSize().height*0.5 + 20);
	m_skill = MenuItemImage::create(StringValue("SkillIcon"),
		StringValue("SkillIcon"), this,
		menu_selector(GameUILayer::onSkillClickCallBack));
	m_skill->setPosition(m_backpack->getPosition().x - m_backpack->getContentSize().width - 20, m_backpack->getPosition().y - 5);
	menu->addChild(m_backpack);
	menu->addChild(m_skill);

	m_worldMap = MenuItemImage::create(StringValue("MapIcon"),
		StringValue("MapIcon"), this,
		menu_selector(GameUILayer::onMapIconClickCallBack));
	m_worldMap->setPosition(size.width - m_worldMap->getContentSize().width*0.5, size.height - m_worldMap->getContentSize().height*0.5 - 20);
	menu->addChild(m_worldMap);

	m_menuBtn = MenuItemImage::create(StringValue("MenuBtn"),
		StringValue("MenuBtn"), this,
		menu_selector(GameUILayer::onMenuClickCallBack));
	m_menuBtn->setPosition(m_worldMap->getPosition().x - m_worldMap->getContentSize().width, m_worldMap->getPosition().y);
	menu->addChild(m_menuBtn);

	auto bloodBg = Sprite::create(StringValue("BarBg"));
	bloodBg->setPosition(headFrame->getPosition().x + headFrame->getContentSize().width + 15, headFrame->getPosition().y + 5);
	auto manaBg = Sprite::create(StringValue("BarBg"));
	manaBg->setPosition(headFrame->getPosition().x + headFrame->getContentSize().width + 15, headFrame->getPosition().y - 25);
	auto bloodBar = Sprite::create(StringValue("BloodBar"));
	m_bloodBar = ProgressTimer::create(bloodBar);
	m_bloodBar->setType(ProgressTimer::Type::BAR);
	m_bloodBar->setMidpoint(ccp(0, 0));
	m_bloodBar->setBarChangeRate(ccp(1, 0));
	m_bloodBar->setPercentage(100);
	m_bloodBar->setPosition(bloodBg->getPosition());
	auto manaBar = Sprite::create(StringValue("ManaBar"));
	m_manaBar = ProgressTimer::create(manaBar);
	m_manaBar->setType(ProgressTimer::Type::BAR);
	m_manaBar->setMidpoint(ccp(0, 0));
	m_manaBar->setBarChangeRate(ccp(1, 0));
	m_manaBar->setPercentage(100);
	m_manaBar->setPosition(manaBg->getPosition());

	m_talkFrame = Sprite::create(StringValue("TalkFrame"));
	m_talkFrame->setPosition(m_talkFrame->getContentSize().width*0.5, m_talkFrame->getContentSize().height*0.5 + 30);
	auto label = LabelTTF::create(StringValue("TalkTip"), "楷体", 20);
	label->setPosition(ccp(label->getContentSize().width*0.5, m_talkFrame->getPosition().y + m_talkFrame->getContentSize().height*0.5 + 15));

	auto editBg = Sprite::create(StringValue("MessageFrame"));
	editBg->setPosition(editBg->getContentSize().width*0.5, editBg->getContentSize().height*0.5);
	m_editFrame = TextFieldTTF::textFieldWithPlaceHolder(StringValue("TalkEditECHO"), "楷体", 16);
	m_editFrame->setColor(ccc3(195, 195, 195));
	m_editFrame->setContentSize(editBg->getContentSize());
	m_editFrame->setPosition(editBg->getPosition());
	m_editFrame->setWidth(130);
	m_editFrame->setDelegate(this);
	m_sendBtn = MenuItemImage::create(StringValue("SendBtn"), StringValue("SendBtn"),
		this, menu_selector(GameUILayer::onSendClickCallBack));
	m_sendBtn->setPosition(editBg->getPosition().x + editBg->getContentSize().width*0.5 + 20, editBg->getPosition().y);
	menu->addChild(m_sendBtn);
	this->addChild(editBg);
	this->addChild(m_editFrame);

	this->addChild(bloodBg);
	this->addChild(manaBg);
	this->addChild(m_bloodBar);
	this->addChild(m_manaBar);
	this->addChild(m_talkFrame);
	this->addChild(label);
}

void GameUILayer::onMapIconClickCallBack(cocos2d::CCObject* sender)
{
	ClickAction();
	SHOW_AND_DELETE_LAYER(WorldMapLayer);
}

void GameUILayer::onBackPackClickCallBack(cocos2d::CCObject* sender)
{
	ClickAction();
	SHOW_AND_DELETE_LAYER(BackPackLayer);
}

void GameUILayer::onSkillClickCallBack(cocos2d::CCObject* sender)
{
	ClickAction();
	SHOW_AND_DELETE_LAYER(SkillLayer);
}

void GameUILayer::onHeadClickCallBack(cocos2d::CCObject* sender)
{
	ClickAction();
}

void GameUILayer::onSendClickCallBack(cocos2d::CCObject* sender)
{
	ClickAction();
}

void GameUILayer::onMenuClickCallBack(cocos2d::CCObject* sender)
{
	ClickAction();
	if (!m_isclickGameMenuLayer)
	{
		m_isclickGameMenuLayer = !m_isclickGameMenuLayer;
		((GameScene*)this->getParent())->pauseAllActions(getParent(), this);
		auto menuLayer = GameMenuLayer::create();
		this->addChild(menuLayer);
	}
}

bool GameUILayer::onTextFieldAttachWithIME(TextFieldTTF * sender)
{
	sender->setScale(1.1);
	sender->setColor(ccc3(255, 255, 255));
	return TextFieldDelegate::onTextFieldAttachWithIME(sender);
}

bool  GameUILayer::onTextFieldDetachWithIME(TextFieldTTF * sender)
{
	sender->setScale(1.0);
	sender->setColor(ccc3(195, 195, 195));
	return TextFieldDelegate::onTextFieldDetachWithIME(sender);
}
void GameUILayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	auto pos = touch->getLocation();
	bool res;
	ATTACH_OR_DETACH(m_editFrame, pos, res);
}

void GameUILayer::resetMenulayer()
{
	m_isclickGameMenuLayer = false;
}

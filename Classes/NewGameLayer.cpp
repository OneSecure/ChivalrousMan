#include"NewGameLayer.h"
#include"GameData.h"
#include"StartMenu.h"
#include"Commen.h"

bool NewGameLayer::init()
{
	if (Layer::init())
	{
		LISTEN_TOUCH(NewGameLayer);

		Size size = SCREEN;
		auto back = Sprite::create(StringValue("SigOnBg"), Rect{ 0,0,size.width,size.height });
		back->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(back);

		STONE_STATION(0.25, 0.5,NewGameLayer::onStoneCallBack, this);
		
		m_bracket[0] = Sprite::create(StringValue("LeftBracket"));
		m_bracket[0]->setPosition(SCREEN.width*0.25 - 70, SCREEN.height*0.57);
		m_bracket[1] = Sprite::create(StringValue("RightBracket"));
		m_bracket[1]->setPosition(SCREEN.width*0.25 + 70, SCREEN.height*0.57);
		m_bracket[0]->setScale(0.8);
		auto move = MoveBy::create(0.3, ccp(-20, 0));
		auto move1 = MoveBy::create(0.3, ccp(20, 0));
		auto addmove = Sequence::createWithTwoActions(move, move1);
		m_bracket[0]->runAction(RepeatForever::create(addmove));
		m_bracket[1]->setScale(0.8);
		auto move2 = MoveBy::create(0.3, ccp(20, 0));
		auto move3 = MoveBy::create(0.3, ccp(-20, 0));
		auto addmove1 = Sequence::createWithTwoActions(move2, move3);
		m_bracket[1]->runAction(RepeatForever::create(addmove1));
		this->addChild(m_bracket[0]);
		this->addChild(m_bracket[1]);

		auto playerAnimation = AnimationCache::getInstance()->getAnimation("Player1");
		auto playerAnimate = Animate::create(playerAnimation);
		auto player = Sprite::create(StringValue("Player1"));
		player->setPosition(SCREEN.width*0.24, SCREEN.height*0.625);
		player->runAction(RepeatForever::create(playerAnimate));
		this->addChild(player);

		ADD_EDIT(m_username, "PlayerNameTip", ccp(size.width*0.32, size.height*0.35), "PlayerName", "EditBg", false, this, this);

		COMMEN_BTN(this, NewGameLayer::onConfirmCallBack,
			NewGameLayer::onCancelCallBack);
		return true;
	}

	return false;
}

void NewGameLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	bool res;
	Vec2 pos = touch->getLocation();
	ATTACH_OR_DETACH(m_username, pos, res);
}

void NewGameLayer::onConfirmCallBack(cocos2d::CCObject* sender)
{

}

void  NewGameLayer::onCancelCallBack(cocos2d::CCObject* sender)
{
	GO_BACK_START_MENU();
}

bool NewGameLayer::onTextFieldAttachWithIME(cocos2d::TextFieldTTF * sender)
{
	sender->setScale(1.1);
	sender->setTextColor(ccc4(13, 203, 17, 255));
	sender->setColorSpaceHolder(ccc4(255, 128, 0, 255));
	return TextFieldDelegate::onTextFieldAttachWithIME(sender);
}

bool NewGameLayer::onTextFieldDetachWithIME(cocos2d::TextFieldTTF * sender)
{
	sender->setScale(1.0);
	sender->setTextColor(ccc4(131, 3, 92, 255));
	sender->setColorSpaceHolder(ccc3(73, 214, 23));
	return TextFieldDelegate::onTextFieldDetachWithIME(sender);
}

void NewGameLayer::onStoneCallBack(cocos2d::CCObject* sender)
{
	switch (dynamic_cast<MenuItemImage*>(sender)->getTag())
	{
	case 101:
		moveBracket(ccp(SCREEN.width*0.25, SCREEN.height * 0.57), 0.5);
		break;
	case 102:
		moveBracket(ccp(SCREEN.width*0.25 * 2, SCREEN.height*0.57), 0.5);
		break;
	case 103:
		moveBracket(ccp(SCREEN.width*0.25 * 3, SCREEN.height*0.57), 0.5);
		break;
	default:
		break;
	}
}

void NewGameLayer::moveBracket(cocos2d::Vec2 dest, float delay)
{
	auto move = MoveTo::create(delay, ccp(dest.x - 70, dest.y));
	m_bracket[0]->runAction(move);
	auto move1 = MoveTo::create(delay, ccp(dest.x + 70, dest.y));
	m_bracket[1]->runAction(move1);
}
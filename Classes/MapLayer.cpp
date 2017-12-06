#include"MapLayer.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"Commen.h"
#include"MapInfo.h"
#include"Player.h"

bool MapLayer::init()
{
	if (Layer::init())
	{
		LISTEN_TOUCH(MapLayer);
		return true;
	}
	return false;
}

bool MapLayer::initMapTexture(const std::string& filename)
{
	auto maptexture = Sprite::create(filename);
	if (maptexture == nullptr) 
	{
		return false;
	}
	maptexture->setAnchorPoint(ccp(0, 0));
	maptexture->setPosition(0, 0);
	this->addChild(maptexture);
	MapInfo::getMapInstance()->setFace(maptexture);

	auto playerFace = Sprite::create();
	auto animation = AnimationCache::getInstance()->getAnimation("Player1");
	auto animate = Animate::create(animation);
	playerFace->runAction(RepeatForever::create(animate));
	this->addChild(playerFace);
	Player::getPlayerInstance()->setFace(playerFace);

	return true;
}

bool MapLayer::readMapInfoInFile(const std::string& filename)
{
	return true;
}

void MapLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	Vec2 pos = touch->getLocation();
	
}
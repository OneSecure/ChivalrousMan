#include"PlayerState.h"
#include"Commen.h"
#include"GameDynamicData.h"

PlayerState::PlayerState(cocos2d::Sprite* face,const std::string& playertype)
{
	m_playerFace = face;
	m_playerType = playertype;
}

PlayerState::~PlayerState()
{

}

void PlayerState::change(const char* name)
{
	char key[40] = { 0 };
	sprintf_s(key, "%s%s", m_playerType.c_str(), name);
	Animation* animation = AnimationCache::getInstance()->getAnimation(key);
	Animate* animate = Animate::create(animation);
	m_playerFace->stopAllActions();
	m_playerFace->runAction(RepeatForever::create(animate));
}
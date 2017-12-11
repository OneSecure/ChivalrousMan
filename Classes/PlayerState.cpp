#include"PlayerState.h"
#include"Commen.h"

PlayerState::PlayerState(cocos2d::Sprite* face)
{
	m_playerFace = face;
}

PlayerState::~PlayerState()
{

}

void PlayerState::change(const char* name)
{
	Animation* animation;
	LoadAnimationFromMinFile(name, 8, 0.15, animation);
	Animate* animate = Animate::create(animation);
	m_playerFace->stopAllActions();
	m_playerFace->runAction(RepeatForever::create(animate));
}
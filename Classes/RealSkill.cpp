#include"RealSkill.h"
#include"Commen.h"
#include"GameData.h"

RealSkill::RealSkill()
{
	
}

RealSkill::~RealSkill()
{
	
}

void RealSkill::died(float dt)
{
	m_parent->removeChild(this);
}

void RealSkill::loadAnimation(std::string name, int nums, float delay)
{
	auto animation = Animation::create();
	std::string filename;
	animation->setDelayPerUnit(0.15);
	for (int i = 1; i <= nums; ++i)
	{
		filename = name + NTS(i) + ".png";
		Texture2D *texture = TextureCache::getInstance()->addImage(filename);
		Rect rect{ 0,0,texture->getContentSize().width,texture->getContentSize().height };
		animation->addSpriteFrameWithTexture(texture, rect);
	}
	AnimationCache::getInstance()->addAnimation(animation, name);
}

cocos2d::Animation* RealSkill::getAnimation(std::string key)
{
	return AnimationCache::getInstance()->getAnimation(key);
}

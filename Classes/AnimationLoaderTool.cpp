#include"AnimationLoaderTool.h"
#include"Commen.h"

Animation* AnimationLoaderTool::loadAnimationFromMinFile(const std::string& name, int num,float delay)
{
	Animation *animation = Animation::create();
	char filename[40] = { 0 };
	animation->setDelayPerUnit(delay);
	for (int i = 1; i <= 8; ++i)
	{
		sprintf_s(filename, "%s%d.png", name, i);
		Texture2D *texture = TextureCache::getInstance()->addImage(filename);
		Rect rect{ 0,0,texture->getContentSize().width,texture->getContentSize().height };
		animation->addSpriteFrameWithTexture(texture, rect);
	}
	return animation;
}

Animation* AnimationLoaderTool::loadAnimationFromLargeFile(const std::string& name, int row, int rank,float delay)
{

}
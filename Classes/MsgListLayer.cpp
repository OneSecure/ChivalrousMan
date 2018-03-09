#include"MsgListLayer.h"
#include"Commen.h"
#include"GameData.h"

bool MsgListLayer::init()
{
	if (Layer::init())
	{
		auto size = SCREEN;
		auto bg = Sprite::create(StringValue(""));
		bg->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(bg);
		return true;
	}
	return false;
}
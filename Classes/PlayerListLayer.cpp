#include"PlayerListLayer.h"
#include"Commen.h"
#include"GameData.h"
#include"PlayerItem.h"
#include"CMClient.h"

bool PlayerListLayer::init()
{
	if (Layer::init())
	{
		auto size = SCREEN;
		auto bg = Sprite::create(StringValue("PlayerListBg"));
		bg->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(bg);
		
		auto titlelabel = LabelTTF::create(StringValue("NearPlayerText"), "¿¬Ìå", 30);
		titlelabel->setColor(Color3B::YELLOW);
		titlelabel->setPosition(size.width*0.5, bg->getPositionY() + bg->getContentSize().height*0.5 - 25);
		this->addChild(titlelabel);
		
		initPlayerItem(bg->getPosition());
		return true;
	}
	return false;
}

void PlayerListLayer::initPlayerItem(cocos2d::Vec2 basePos)
{
	Player_Info info;
	info.rolename = StringValue("NpcValligeCN");
	info.playertype = "Player3";
	auto item = PlayerItem::create(info);
	item->setPosition(basePos.x - 25, basePos.y);
	this->addChild(item);
}
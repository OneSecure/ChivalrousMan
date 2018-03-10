#include"TeamLayer.h"
#include"Commen.h"
#include"GameData.h"
#include"CameraPlayer.h"
#include"TeamMsgItem.h"
#include"CMClient.h"

bool TeamLayer::init()
{
	if (Layer::init())
	{
		auto size = SCREEN;
		setName("TeamLayer");
		auto bg = Sprite::create(StringValue("MsgListBg"));
		bg->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(bg);
		
		std::string nametext;
		Vec2 pos = bg->getPosition();
		pos.y = pos.y + bg->getContentSize().height*0.5 - 80;
		if (PlayerTeamStatus() == P_STATUS_NORMAL)
		{
			nametext = StringValue("ApplyListText");
			initApplyList(pos);
		}
		else
		{
			nametext = StringValue("MemberText");
			initTeamMember(pos);
		}
		auto namelabel = LabelTTF::create(nametext, "¿¬Ìå", 30);
		namelabel->setColor(Color3B::YELLOW);
		namelabel->setPosition(bg->getPositionX(), bg->getPositionY() + bg->getContentSize().height*0.5 - 18);
		this->addChild(namelabel);
		return true;
	}
	return false;
}

void TeamLayer::initApplyList(const cocos2d::Vec2& basePos)
{
	int index = 0;
	for (auto var : CMClient::getInstance()->getApplyTeamList())
	{
		auto item = TeamMsgItem::create(var);
		item->setPosition(basePos.x, basePos.y - index * 80);
		this->addChild(item);
		++index;
	}
}

void TeamLayer::initTeamMember(const cocos2d::Vec2& basePos)
{
	
}
#include"TaskLayer.h"
#include"Commen.h"
#include"GameData.h"
#include"TaskItem.h"

bool TaskLayer::init()
{
	if (Layer::init())
	{
		auto size = SCREEN;
		auto bg = Sprite::create(StringValue("TaskBg"));
		bg->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(bg);

		auto labeltitle = LabelTTF::create(StringValue("TaskTitle"), "¿¬Ìå", 30);
		labeltitle->setPosition(size.width*0.5, size.height*0.5 + bg->getContentSize().height*0.5 - 25);
		labeltitle->setColor(Color3B::YELLOW);
		this->addChild(labeltitle);
		
		initTaskItem(bg->getPosition());
		return true;
	}
	return false;
}

void  TaskLayer::initTaskItem(cocos2d::Vec2 basePos)
{
	basePos.y += 202;
	int index = 0;
	for (auto var : TaskSystem::getInstance()->getpickedupTask())
	{
		TaskItem* taskitem = TaskItem::create(var);
		taskitem->setPosition(basePos.x, basePos.y - index * 80);
		this->addChild(taskitem);
		++index;
	}
}
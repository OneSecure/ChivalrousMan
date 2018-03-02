#include"TaskItem.h"
#include"Commen.h"
#include"GameData.h"

TaskItem*  TaskItem::create(const TaskInfo& tinfo)
{
	TaskItem* pRet = new TaskItem;
	if (pRet&&pRet->init(tinfo))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool TaskItem::init(const TaskInfo& tinfo)
{
	if (Node::init())
	{
		auto bg = Sprite::create(StringValue("TaskItemBg"));
		this->addChild(bg);
		
		auto labelname = LabelTTF::create(tinfo.name, "楷体", 25);
		labelname->setPosition(-20, 28);
		labelname->setAnchorPoint(ccp(0, 1));
		labelname->setColor(Color3B::BLACK);
		this->addChild(labelname);

		auto labelprocess = LabelTTF::create(StringValue("Process") + ":" + NTS(tinfo.curschedule) + "/" + NTS(tinfo.allschedule),
			"楷体", 15);
		labelname->setAnchorPoint(ccp(1, 1));
		labelprocess->setPosition(140, -25);
		labelprocess->setColor(Color3B::RED);
		this->addChild(labelprocess);
		
		auto labeldest = LabelTTF::create(StringValue("DestMen") + ":" + TaskSystem::getInstance()->m_entocn[tinfo.destwho], "楷体", 15);
		labeldest->setColor(Color3B::GREEN);
		labeldest->setAnchorPoint(ccp(0, 0));
		labeldest->setPosition(-150, -32);
		this->addChild(labeldest);
		
		std::string dtstr;
		switch (tinfo.type)
		{
		case T_KILL:
			dtstr = StringValue("Kill") + TaskSystem::getInstance()->m_entocn[tinfo.schedulewho];
			break;
		case T_ACCESS:
			dtstr=StringValue("Access")+ TaskSystem::getInstance()->m_entocn[tinfo.schedulewho];
			break;
		case T_COLLECT:
			dtstr = StringValue("Collect") + TaskSystem::getInstance()->m_entocn[tinfo.schedulewho];
			break;
		}
		auto labeldetail = LabelTTF::create(dtstr,"楷体", 15);
		labeldetail->setColor(Color3B::ORANGE);
		labeldetail->setAnchorPoint(ccp(0, 0.5));
		labeldetail->setPosition(-120, -8);
		this->addChild(labeldetail);

		auto labelglod = LabelTTF::create(StringValue("Glod") + ":" + NTS(tinfo.glodreward),
			"楷体", 15);
		labelglod->setColor(ccc3(255, 201, 14));
		labelglod->setAnchorPoint(ccp(1, 1));
		labelglod->setPosition(170, 25);
		this->addChild(labelglod);

		auto labelexp = LabelTTF::create(StringValue("Exp") + ":" + NTS(tinfo.expreward),
			"楷体", 15);
		labelexp->setColor(ccc3(255, 127, 39));
		labelexp->setAnchorPoint(ccp(1, 0.5));
		labelexp->setPosition(170, 0);
		this->addChild(labelexp);
		return true;
	}
	return false;
}
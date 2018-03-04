#include"BeginScene.h"
#include"BeginLayer.h"
#include"CMClient.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"Commen.h"
#include"LoadingLayer.h"
#include<thread>
#include<functional>

bool BeginScene::init()
{
	if (Scene::init())
	{
		auto beginlayer = BeginLayer::create();
		this->addChild(beginlayer);
		
		if (GetIntData("IsConnectNet")!=1)
		{
			auto loadinglayer = LoadingLayer::create(StringValue("NetConnectText"), StringValue("LoadingIcon"), false);
			loadinglayer->setName("loadinglayer");
			this->addChild(loadinglayer);
			auto func = [beginlayer, this] {
				if (CMClient::getInstance()->Connect())
				{
					beginlayer->showBtn();
					SetIntData("IsConnectNet", 1);
					this->removeChildByName("loadinglayer");
				}
				else
				{
					MessageBox("请检查网络连接状况!", "提示");
					this->removeChildByName("loadinglayer");
				}
			};
			std::thread th{ func };
			th.detach();
		}
		else
		{
			beginlayer->showBtn();
		}
		
		return true;
	}
	return false;
}

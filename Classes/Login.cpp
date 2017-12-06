#include"Login.h"
#include"GameData.h"
#include"LoginLayer.h"
#include"Commen.h"

bool Login::init()
{
	if (Scene::init())
	{
		auto loginLayer = LoginLayer::create();
		this->addChild(loginLayer);
		return true;
	}
	return false;
}
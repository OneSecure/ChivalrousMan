#include"SignOn.h"
#include"SigOnLayer.h"
#include"Commen.h"

bool SignOn::init()
{
	if (Scene::init())
	{
		auto sigLayer = SigOnLayer::create();
		this->addChild(sigLayer);
		return true;
	}
	return false;
}
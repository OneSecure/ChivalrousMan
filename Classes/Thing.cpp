#include"Thing.h"
#include"Commen.h"

Thing::Thing()
{

}

Thing::~Thing()
{

}

Thing* Thing::createWithImage(const std::string& filename)
{
	Thing* pRet = new Thing;
	if (pRet&&pRet->init(filename))
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

bool Thing::init(const std::string& filename)
{
	if (MenuItemImage::init())
	{
		auto image = Sprite::create(filename);
		this->setNormalImage(image);
		this->setSelectedImage(image);
		return true;
	}
	return false;
}

void Thing::showDetail()
{

}
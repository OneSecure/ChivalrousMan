#pragma once
#ifndef __MAP_LAYER_H__
#define __MAP_LAYER_H__
#include"PreProcess.h"
#include<string>

class MapLayer :public cocos2d::Layer
{
	CLASS_ESSENTAIL(MapLayer)
	CREATE_FUNC(MapLayer)
public:
	virtual bool init();

	bool initMapTexture(const std::string& filename);
	
	bool readMapInfoInFile(const std::string& filename);
private:
	virtual void onTouchEnded(cocos2d::Touch *touch,cocos2d::Event *unused_event) override;
};

#endif // !__MAP_LAYER_H__


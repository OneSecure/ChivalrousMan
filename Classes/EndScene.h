#pragma once
#ifndef __END_SCENE_H__
#define __END_SCENE_H__
#include"PreProcess.h"

class EndScene :public cocos2d::Scene
{
public:
	CLASS_ESSENTAIL(EndScene)
	CREATE_FUNC(EndScene)

	virtual bool init();

	void EndCallBack(float dv);
private:

};

#endif // !__END_SCENE_H__

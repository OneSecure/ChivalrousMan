#pragma once
#ifndef __SIGN_ON_H__
#define __SIGN_ON_H__
#include"PreProcess.h"

class SignOn:public cocos2d::Scene
{
public:
	CLASS_ESSENTAIL(SignOn)
	CREATE_FUNC(SignOn)

	virtual bool init() override;
private:

};

#endif // !__SIGN_ON_H__


#pragma once
#ifndef __PRE_PROCESS_H__
#define __PRE_PROCESS_H__
#include"cocos2d.h"

#define CLASS_ESSENTAIL(__TYPE__)  \
    private:  \
           __TYPE__(){} \
    public:          \
           virtual ~__TYPE__(){}

#define LISTEN_TOUCH(__TYPE__)  \
         setTouchEnabled(true); \
         auto touchListener = EventListenerTouchOneByOne::create();   \
         touchListener->onTouchBegan = CC_CALLBACK_2(__TYPE__::onTouchBegan, this); \
         touchListener->onTouchMoved = CC_CALLBACK_2(__TYPE__::onTouchMoved, this);  \
         touchListener->onTouchEnded = CC_CALLBACK_2(__TYPE__::onTouchEnded, this);   \
         _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this)

#endif // !__PRE_PRECESS_H__


#pragma once
#ifndef __PRE_PROCESS_H__
#define __PRE_PROCESS_H__
#include"cocos2d.h"

#define CLASS_ESSENTAIL(__TYPE__)  \
    private:  \
           __TYPE__(){} \
    public:          \
           virtual ~__TYPE__(){}

#define Inherit(__TYPE__) :public __TYPE__

enum class Dir
{
	Dir_Left,
	Dir_Down,
	Dir_Right,
	Dir_Up,
};

enum class Player_Type
{
	Player1_Type,
	Player2_Type,
	Player3_Type,
};

#endif // !__PRE_PRECESS_H__


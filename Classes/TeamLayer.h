#pragma once
#ifndef __TEAM_LAYER_H__
#define  __TEAM_LAYER_H__
#include"PreProcess.h"

class TeamLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(TeamLayer)
	CREATE_FUNC(TeamLayer)
public:
	bool init();
private:
	/*
	*初始化申请列表
	*/
	void initApplyList(const cocos2d::Vec2& basePos);

	/*
	*初始化队伍成员
	*/
	void initTeamMember(const cocos2d::Vec2& basePos);
};

#endif //!__TEAM_LAYER_H__

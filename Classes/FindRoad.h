#pragma once
#ifndef __FIND_ROAD_H__
#define __FIND_ROAD_H__
#include"PreProcess.h"
#include<list>
#include<stack>

struct _Pos
{
	int x;
	int y;
	int g;
	int h;
	int f;
	_Pos* parent;

	_Pos()
	{
		g = 0;
		h = 0;
		f = 0;
		parent = NULL;
	}
};

class FindRoad
{
public:
	FindRoad(cocos2d::Vec2 startPos,cocos2d::Vec2 targetPos,int** map,int countx, int county);
	~FindRoad();

	void ExecuteAStar();

	bool IsValid(_Pos& pos);

	int CalcH(_Pos& pos);

	_Pos* OnOpenList(_Pos& pos);

	bool OnCloseList(_Pos& pos);

	std::stack<cocos2d::Vec2> GetRoadList();

	inline bool isHasRoad() { return hasRoad; }

	std::list<_Pos*>::iterator FindFromOpenMin();
private:
	void GetRoad();

	std::list<_Pos*> m_openList;
	std::list<_Pos*> m_closeList;
	std::stack<cocos2d::Vec2> m_roadList;

	_Pos* m_startPos;
	_Pos* m_curPos;
	_Pos* m_targetPos;
	int m_countx;
	int m_county;
	int** m_map;
	bool hasRoad = true;
};

#endif // !__FIND_ROAD_H__


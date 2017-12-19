#include"FindRoad.h"
#include"Commen.h"
 
FindRoad::FindRoad(cocos2d::Vec2 startPos, cocos2d::Vec2 targetPos, int** map, int countx, int county)
{
	m_startPos = new _Pos;
	m_targetPos = new _Pos;
	m_startPos->x = startPos.x;
	m_startPos->y = startPos.y;
	m_targetPos->x = targetPos.x;
	m_targetPos->y = targetPos.y;
	m_map = map;
	m_countx = countx;
	m_county = county;
}

FindRoad::~FindRoad()
{
	for (auto it = m_openList.begin(); it != m_openList.end(); ++it)
	{
		delete *it;
	}
	for (auto it = m_closeList.begin(); it != m_closeList.end(); ++it)
	{
		delete *it;
		*it = nullptr;
	}
	delete m_targetPos;
	m_targetPos = nullptr;
}

void FindRoad::ExecuteAStar()
{
	m_curPos = m_startPos;
	int dir[][2] = { {1,0},{-1,0},{0,1},{0,-1},{1,-1},{-1,1},{1,1},{-1,-1} };
	
	do
	{
		for (int i = 0; i < 8; ++i)
		{
			_Pos *tmp = new _Pos;
			tmp->x = m_curPos->x + dir[i][0];
			tmp->y = m_curPos->y + dir[i][1];
			if (IsValid(*tmp) && !OnCloseList(*tmp))
			{
				_Pos* it = OnOpenList(*tmp);
				if (it)
				{
					float newg = m_curPos->g + 1;
					if (newg < it->g)
					{
						it->parent = m_curPos;
						it->g = newg;
						it->f = it->g + it->h;
					}
					delete tmp;
					tmp = nullptr;
				}
				else
				{
					tmp->g = m_curPos->g + 1;
					tmp->h = CalcH(*tmp);
					tmp->f = tmp->g + tmp->h;
					tmp->parent = m_curPos;
					m_openList.push_back(tmp);
				}
			}
			else
			{
				delete tmp;
				tmp = nullptr;
			}
		}

		if (m_openList.empty())
		{
			hasRoad = false;
			break;
		}

		auto it=FindFromOpenMin();
		m_closeList.push_back(m_curPos);
		m_curPos = (*it);
		m_openList.erase(it);
	} while (m_curPos->x != m_targetPos->x || m_curPos->y != m_targetPos->y);
	GetRoad();
}

bool FindRoad::IsValid(_Pos& pos)
{
	if (pos.x >= 0 && pos.x < m_countx
		&&pos.y >= 0 && pos.y < m_county
		&&(m_map[pos.y][pos.x]==0||m_map[pos.y][pos.x]==-1))
	{
		return true;
	}
	return false;
}

int FindRoad::CalcH(_Pos& pos)
{
	return sqrtf((pos.x - m_targetPos->x)*(pos.x - m_targetPos->x) + (pos.y - m_targetPos->y)*(pos.y - m_targetPos->y));
}

bool FindRoad::OnCloseList(_Pos& pos)
{
	for (auto it = m_closeList.begin(); it != m_closeList.end(); ++it)
	{
		if ((*it)->x == pos.x&&(*it)->y == pos.y)
		{
			return true;
		}
	}
	return false;
}

_Pos* FindRoad::OnOpenList(_Pos& pos)
{
	for (auto it = m_openList.begin(); it != m_openList.end(); ++it)
	{
		if ((*it)->x == pos.x && (*it)->y == pos.y)
		{
			return *it;
		}
	}
	return NULL;
}

std::list<_Pos*>::iterator FindRoad::FindFromOpenMin()
{
	auto tmp = m_openList.begin();
	for (auto it=m_openList.begin() ; it != m_openList.end(); ++it)
	{
		if ((*tmp)->f > (*it)->f)
		{
			tmp = it;
		}
	}
	return tmp;
}

void FindRoad::GetRoad()
{
	_Pos *pos = m_curPos;
	while (pos->parent!=NULL)
	{
		m_roadList.push(Vec2{ (float)pos->x,(float)pos->y });
		pos = pos->parent;
	} 
}

std::stack<cocos2d::Vec2> FindRoad::GetRoadList()
{
	return m_roadList;
}
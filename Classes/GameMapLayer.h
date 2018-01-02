#pragma once
#ifndef __MAP_LAYER_H__
#define __MAP_LAYER_H__
#include"PreProcess.h"
#include<string>
#include<vector>

/*
*class GameMapLayer
*��Ϸ��ͼ�㣬��Ҫ���ڻ��Ƶ�ͼ
*/
class GameMapLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(GameMapLayer)
	CREATE_FUNC(GameMapLayer)
public:
	bool init() override;

	/*
	*loadMapTexture(std::string name);
	*���ļ����м��ص�ͼ����
	*@param name:�ļ�������
	*/
	bool loadMapTexture(std::string name);

	/*
	*drawMap(float startx, float starty);
	*���ƴ�����Ļ֮�ڵĵ�ͼ��
	*@param stratx�����ƵĿ�ʼx����
	*@param starty�����ƵĿ�ʼy����
	*/
	bool drawMap(float startx, float starty);

	/*
	*updateDoorScreenPos();
	*���µ�ͼ����������Ļ�ϵ�λ��
	*/
	void updateDoorScreenPos();
private:
	/*
	*������ͼ�ϵĴ�����
	*/
	void generateDoors();

	/*
	*���õ�ͼ��Ϊ���ɼ�
	*/
	void resetMap();

	std::vector<cocos2d::Sprite*> m_mapList;

	cocos2d::Node* m_curMaps;

	std::vector<cocos2d::Sprite*> m_doors;
	cocos2d::Sprite* m_door = nullptr;
	cocos2d::Vec2 m_doorPos;
};

#endif // !__MAP_LAYER_H_
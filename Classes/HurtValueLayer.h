#pragma once
#ifndef __HURT_VAUE_LAYER_H__
#define __HURT_VAUE_LAYER_H__
#include"PreProcess.h"

/*
*class HurtsValueLayer
*��ʾ�˺�ֵ��UI���
*/
class HurtsValueLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(HurtsValueLayer)
public:
	/*
	*HurtsValueLayer* createWithInfo(Vec2 pos, float hurt);
	*ͨ��λ�ú��˺�ֵ����
	*@param pos:�˺�ֵ��ʾλ��
	*@param hurt���˺�ֵ
	*/
	static HurtsValueLayer* createWithInfo(cocos2d::Vec2 pos, float hurt);

	bool init(cocos2d::Vec2 pos, float hurt);
private:
	/*
	*��ʧ
	*/
	void dead(float dt);
};


#endif // !__HURT_VAUE_LAYER_H__

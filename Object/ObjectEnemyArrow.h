#pragma once

#include "ObjectEnemy.h"
#include "Vec2.h"

// �w�肵�������ɔ��ł����G
class ObjectEnemyArrow : public ObjectEnemy
{
public:
	ObjectEnemyArrow();
	virtual ~ObjectEnemyArrow();

	virtual void update();
	virtual void draw();

	// ���ł����������w�肷��(��������0�x�Ƃ��Ď��v���̊p�x���w�肷��)
	void setDir(float degree);

private:
	// ���ł��������̌X��
	float m_angle;

	// ���ł�������
	Vec2 m_vec;
};
#pragma once

#include "ObjectEnemy.h"
#include "Vec2.h"

// �w�肵�������ɔ��ł����G
class ObjectEnemyThrow : public ObjectEnemy
{
public:
	ObjectEnemyThrow();
	virtual ~ObjectEnemyThrow();

	virtual void update();

private:
	// ���ł�������
	Vec2 m_vec;
};
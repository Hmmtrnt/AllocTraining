#pragma once

#include "ObjectEnemy.h"
#include "Vec2.h"

// 指定した方向に飛んでいく敵
class ObjectEnemyArrow : public ObjectEnemy
{
public:
	ObjectEnemyArrow();
	virtual ~ObjectEnemyArrow();

	virtual void update();
	virtual void draw();

	// 飛んでいく方向を指定する(左方向を0度として時計回りの角度を指定する)
	void setDir(float degree);

	// 飛んでいく位置を指定する
	void setTaget(Vec2 target) { m_target = target; }

private:
	// 飛んでいく方向
	double m_rad;

	Vec2 m_vec;

	// ターゲット位置
	Vec2 m_target;
};
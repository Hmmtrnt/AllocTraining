#pragma once

#include "ObjectEnemy.h"
#include "Vec2.h"

// 指定した方向に飛んでいく敵
class ObjectEnemyDir : public ObjectEnemy
{
public:
	ObjectEnemyDir();
	virtual ~ObjectEnemyDir();

	virtual void update();

private:

};
#include "ObjectEnemyThrow.h"
#include "game.h"
#include "DxLib.h"

namespace
{
	constexpr float kSpeed = 5.0f;
}

ObjectEnemyThrow::ObjectEnemyThrow() :
	m_vec()
{

}

ObjectEnemyThrow::~ObjectEnemyThrow()
{

}

void ObjectEnemyThrow::update()
{
	if (!m_isExist)	return;
	m_pos += m_vec;
}
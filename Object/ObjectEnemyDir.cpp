#include "ObjectEnemyDir.h"
#include "game.h"
#include "DxLib.h"
#include <math.h>

namespace
{
	constexpr float kSpeed = 5.0f;
}

ObjectEnemyDir::ObjectEnemyDir() :
	m_vec()
{

}

ObjectEnemyDir::~ObjectEnemyDir()
{

}

void ObjectEnemyDir::update()
{
	if (!m_isExist)	return;
	rotation += rotateSpeed;
	m_pos += m_vec;
	if (m_pos.x <= -16.0f || m_pos.x >= Game::kScreenWidth + 10.0f ||
		m_pos.y <= -16.0f || m_pos.y >= Game::kScreenHeight+ 10.0f)
	{
		m_isExist = false;
	}
}

void ObjectEnemyDir::setDir(float degree)
{
	float rad = degree * DX_PI_F / 180.0f;

	m_vec.x = cosf(rad);
	m_vec.y = sinf(rad);
	m_vec *= kSpeed;
}
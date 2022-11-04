#include "ObjectEnemy.h"
#include "game.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	// ‘¬“x
	constexpr float kSpeed = 8.0f;
	// ‰ñ“]‘¬“x
	constexpr float kRotateSpeed = 1.0f;
}

ObjectEnemy::ObjectEnemy() :
	m_hGraph(-1),
	m_sGraphX(0),
	m_sGraphY(0),
	rotation(0.0f),
	rotateSpeed(-0.1f),
	m_isExist(false),
	m_pos()
{

}

ObjectEnemy::~ObjectEnemy()
{

}

void ObjectEnemy::init()
{
	m_isExist = false;
	GetGraphSize(m_hGraph, &m_sGraphX, &m_sGraphY);
}

void ObjectEnemy::end()
{

}

void ObjectEnemy::update()
{
	if (!m_isExist)	return;

	rotation += rotateSpeed;
	m_pos.x -= kSpeed;
	if (m_pos.x <= -16.0f)
	{
		m_isExist = false;
	}
}

void ObjectEnemy::draw()
{
	if (!m_isExist)	return;
	//DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_hGraph, true);
	DrawRotaGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), 2.0f, rotation, m_hGraph, true, false);
}

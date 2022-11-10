#include "ObjectEnemyArrow.h"
#include "game.h"
#include "DxLib.h"
#include <math.h>

namespace
{
	constexpr float kSpeed = 3.0f;
}

ObjectEnemyArrow::ObjectEnemyArrow() :
	m_rad(0),
	m_vec()
{

}

ObjectEnemyArrow::~ObjectEnemyArrow()
{

}

void ObjectEnemyArrow::update()
{
	if (!m_isExist)	return;
	// �i�ޕ�����ύX����
	// m_rad��ύX����
	//m_rad += 0.02f;
	//m_rad -= 0.02f;

	// �p�x����x�N�g���𐶐�����
	Vec2 vec;
	vec.x = cosf(m_rad) * kSpeed;
	vec.y = sinf(m_rad) * kSpeed;
	// �ʒu�Ƀx�N�g�������Z
	m_pos += vec;


	// �v���C���[�ʒu(m_target)�Ɍ������悤�ɂ���
	//Vec2 dir = m_target - m_pos;
	//dir = dir.normalize();
	//dir *= kSpeed;

	//// �i�s�����Ɍ���
	//m_rad = atan2(dir.y, dir.x);

	//m_vec = dir;
	//m_pos += m_vec;


	//Vec2 vec = m_vec;



	if (m_pos.x <= -16.0f || m_pos.x >= Game::kScreenWidth + 10.0f ||
		m_pos.y <= -16.0f || m_pos.y >= Game::kScreenHeight+ 10.0f)
	{
		m_isExist = false;
	}
}

void ObjectEnemyArrow::draw()
{
	if (!m_isExist)	return;
	
	//double angle = atan2(m_target - m_pos, m_pos - m_target);
	int width = 0;
	int height = 0;
	GetGraphSize(m_hGraph, &width, &height);

	//DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_hGraph, true);
	DrawRotaGraph(static_cast<int>(m_pos.x) + width / 2, static_cast<int>(m_pos.y) + height / 2, 2.0f, m_rad, m_hGraph, true, false);
}

void ObjectEnemyArrow::setDir(float degree)
{
	m_rad = degree * DX_PI_F / 180.0f;

	m_vec.x = cosf(m_rad);
	m_vec.y = sinf(m_rad);
	m_vec *= kSpeed;
}
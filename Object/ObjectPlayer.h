#pragma once

#include "Vec2.h"

class SceneMain;

class ObjectPlayer
{
public:
	ObjectPlayer();
	virtual ~ObjectPlayer();

	virtual void init();
	virtual void end();

	virtual void update();
	virtual void draw();

	void setHandle(int handle) { m_hGraph = handle; }

	Vec2 getPos() const { return m_pos; }

protected:
	// �O���t�B�b�N�n���h��
	int		m_hGraph;
	// ������W
	Vec2	m_pos;
};
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
	// グラフィックハンドル
	int		m_hGraph;
	// 左上座標
	Vec2	m_pos;
};
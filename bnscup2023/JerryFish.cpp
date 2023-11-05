﻿#include "stdafx.h"
#include "JerryFish.hpp"

void JerryFish::move()
{
	const RectF tank = m_aquarium._frame.stretched(-m_width / 4, -m_height / 2)
		.movedBy(-m_width / 4, -m_height / 2).scaled(0.9);

	m_time += Scene::DeltaTime();
	if (JerryFish::interval <= m_time)
	{
		m_to = RandomVec2(tank);
		m_time -= JerryFish::interval;
		JerryFish::interval = Random(0.3, 7.0);
	}
	m_point = Math::SmoothDamp(m_point, m_to, m_v, 1.0);
	m_circleCenter = { m_point.x + m_width / (2 * m_animNum), m_point.y + m_height / 2 };
}

void JerryFish::move(Vec2 to)
{
	m_point = to;
}

bool JerryFish::isCollision(const CollisionImage& ci) const
{
	return m_circle.movedBy(m_circleCenter)
		.intersects(ci.getCircle().moveBy(ci.getCircleCenter()));
}

void JerryFish::draw() const
{
	//動く範囲がどこか表示
	//const RectF tank = m_aquarium._frame.stretched(-m_width / 4, -m_height / 2)
	//	.movedBy(-m_width / 4, -m_height / 2).scaled(0.9);
	//tank.drawFrame(2, 2, Palette::Orange);

	//　当たり判定がどこにあるか表示
	//m_circle.movedBy(m_circleCenter)
	//	.draw(ColorF{ 1.0, 1.0, 0.0, 0.2 })
	//	.drawFrame(2, Palette::Yellow);

	const uint64 t = Time::GetMillisec();
	const int32 x = (t / m_speed % m_animNum);
	m_texture(x * (m_texture.width() / m_animNum),
		0, m_texture.width() / m_animNum, m_texture.height())
		.mirrored(0 < m_v.x).scaled(m_scale).draw(m_point);
}

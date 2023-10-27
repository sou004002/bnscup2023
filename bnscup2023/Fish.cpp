#include "stdafx.h"
#include "Fish.hpp"

double interval = 1.0;

void Fish::move()
{
	const RectF tank{ 20, 20 ,760, 560 };

	m_time += Scene::DeltaTime();
	if (interval <= m_time)
	{
		m_to = RandomVec2(tank);
		m_time -= interval;
		interval = Random(0.3, 7.0);
	}
	m_point = Math::SmoothDamp(m_point, m_to, m_v, 1.0);
}

void Fish::draw() const
{
	const uint64 t = Time::GetMillisec();
	const int32 x = (t / m_speed % m_animNum);
	m_texture(x * (m_texture.width() / m_animNum),
		0, m_texture.width() / m_animNum, m_texture.height())
		.mirrored(0 < m_v.x).scaled(m_scale).draw(m_point);
}

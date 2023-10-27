#include "stdafx.h"
#include "Fish.hpp"

double interval = 1.0;

void Fish::move()
{
	const RectF tank{ 20, 20 ,760, 560 };

	this->m_time += Scene::DeltaTime();
	if (interval <= this->m_time)
	{
		this->m_to = RandomVec2(tank);
		this->m_time -= interval;
		interval = Random(0.3, 7.0);
	}
	this->m_p = Math::SmoothDamp(
		this->m_p, this->m_to, this->m_v, 1.0);
}

void Fish::draw() const
{
	const uint64 t = Time::GetMillisec();
	const int32 x = (t / 250 % m_animCnt);
	this->m_texture(x * (m_texture.width() / m_animCnt), 0, m_texture.width() / m_animCnt, m_texture.height()).mirrored(0 < this->m_v.x)
		.resized(this->m_s).drawAt(this->m_p);
}

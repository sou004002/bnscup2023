#include "stdafx.h"
#include "Garbage.hpp"

void Garbage::draw() const
{
	//分割数
	int32 div = 4;
	int32 tex_w = m_texture.width() / div;
	this->m_texture(tex_w * this->g_Cut, 0, tex_w, m_texture.height()).resized(this->m_scale).drawAt(this->m_point);
}

void Garbage::putpoints(Vec2 pos)
{
	this->g_p = pos;
	this->g_x = pos.x;
}

void Garbage::changehitter(double t)
{
	if (this->g_time <= t) {
		this->g_hit = true;
	}
}

bool Garbage::gethitter() const
{
	bool judge;
	judge = this->g_hit;
	return judge;
}

Array<Garbage> Garbage::GenerateRandomPoints(const Rect& rect, double radius, double size, Image tex, bool clip)
{
	Array<Garbage> garbage;
	PoissonDisk2D pd{ rect.size, radius };
	double time = 0.0;
	double const cooltime = 3.0;

	for (const auto& point : pd.getPoints())
	{
		int32 place = Random(3);
		Vec2 pos = (point + rect.pos);
		Garbage gab(size, tex, time, place);
		if (clip && (not rect.contains(pos)))
		{
			continue;
		}
		gab.putpoints(pos);
		gab.setM_point(pos);
		garbage << gab;
		if (count % 10 == 0) {
			cooltime -= 0.5;
		}
		if (cooltime <= 0) {
			cooltime = 0.1;
		}
		time += cooltime;
		count += 1;
	}

	return garbage;
}


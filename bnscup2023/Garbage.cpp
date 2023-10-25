#include "stdafx.h"
#include "Garbage.hpp"

void Garbage::draw() const
{
	this->g_texture.resized(this->g_s).drawAt(this->g_p);
}

void Garbage::putpoints(Vec2 pos)
{
	this->g_p = pos;
}
void Garbage::changepos()
{
	if (this->g_p.y < 500)
	{
		this->g_p.y = this->g_p.y + 1;
	}

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

Array<Garbage> Garbage::GenerateRandomPoints(const Rect& rect, double radius, int32 size, Texture tex, bool clip)
{
	Array<Garbage> garbage;
	PoissonDisk2D pd{ rect.size, radius };
	double time = 0.0;

	for (const auto& point : pd.getPoints())
	{
		Vec2 pos = (point + rect.pos);
		Garbage gab(size, tex, time);
		if (clip && (not rect.contains(pos)))
		{
			continue;
		}
		gab.putpoints(pos);
		garbage << gab;
		time = time + 3.0;
	}

	return garbage;
}

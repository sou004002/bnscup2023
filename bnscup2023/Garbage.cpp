﻿#include "stdafx.h"
#include "Garbage.hpp"

void Garbage::draw() const
{
	//分割数
	int32 div = 4;
	int32 tex_w = g_texture.width() / div;
	this->g_texture(tex_w * this->g_Cut, 0, tex_w, g_texture.height()).resized(this->g_scale).drawAt(this->g_p);
	this->g_circle.drawFrame();
}

void Garbage::putpoints(Vec2 pos)
{
	int32 radius = 7;
	this->g_p = pos;
	this->g_x = pos.x;
	this->g_circle =  Circle { pos, radius };
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

Circle Garbage::getcircle()
{
	return this->g_circle;
}

Array<Garbage> Garbage::GenerateRandomPoints(const Rect& rect, double radius, double size, Texture tex, bool clip)
{
	Array<Garbage> garbage;
	PoissonDisk2D pd{ rect.size, radius };
	double time = 0.0;
	double cooltime = 3.0;
	int32 count = 1;

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


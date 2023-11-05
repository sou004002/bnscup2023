#include "stdafx.h"
#include "Garbage.hpp"


//double time = 0;
void Garbage::draw(bool c) const
{
	//分割数
	int32 div = 4;
	int32 tex_w = g_texture.width() / div;
	if (c == true)
	{
		//Print << U"ハイライト";
		this->g_texture(tex_w * this->g_Cut, 0, tex_w, g_texture.height()).resized(this->g_scale).drawAt(this->g_p, ColorF{1.0, 0.7});
		//できたら網を傾ける
	}
	else
	{
		//Print << U"通常";
		this->g_texture(tex_w * this->g_Cut, 0, tex_w, g_texture.height()).resized(this->g_scale).drawAt(this->g_p);
	}
	/*this->g_circle.drawFrame();*/
}

void Garbage::putpoints(Vec2 pos)
{
	int32 radius;
	this->g_p = pos;
	this->g_x = pos.x;
	if (g_Cut == 2 || g_Cut==3) {
		this->g_circle = Circle{ pos, g_scale*0.3};
	}
	else {
		this->g_circle = Circle{ pos, g_scale*0.4};

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

Circle Garbage::getcircle() const
{
	return this->g_circle;
}

Array<Garbage> Garbage::GenerateRandomPoints(const Rect& rect, double radius, double size, Texture tex,double speed,bool clip)
{
	Array<Garbage> garbage;
	PoissonDisk2D pd{ rect.size, radius };
	int32 count = 1;
	Garbage::time = 0;
	Garbage::coolTime = 3.0;

	for (const auto& point : pd.getPoints())
	{
		int32 place = Random(3);
		Vec2 pos = (point + rect.pos);
		Garbage gab(size, tex, Garbage::time, place);
		if (clip && (not rect.contains(pos)))
		{
			continue;
		}
		gab.putpoints(pos);
		garbage << gab;
		if (count % 10 == 0) {
			Garbage::coolTime -= 0.5;
		}
		if (Garbage::coolTime <= 1.5) {
			Garbage::coolTime = 1.5;
		}
		Garbage::time += Garbage::coolTime;
		count += 1;
	}

	return garbage;
}

void Garbage::set_del(bool x)
{
	this->g_del = x;
}

bool Garbage::get_del() const
{
	return this->g_del;
}
void Garbage::set_hit(bool x)
{
	this->g_hit = x;
}
double Garbage::get_time() const
{
	return this->g_time;
}
void Garbage::set_time(double t) {
	this->g_time = t;
}

Garbage& Garbage::operator=(const Garbage& garbage)
{
	g_x = garbage.g_x;
	g_p = garbage.g_p;
	g_scale = garbage.g_scale;
	g_texture = garbage.g_texture;
	g_time = garbage.g_time;
	g_hit = garbage.g_hit;
	g_Cut = garbage.g_Cut;
	g_circle = garbage.g_circle;
	g_del = garbage.g_del;
	return *this;
}


#pragma once
#include <Siv3D.hpp>

class Garbage
{
public:
	Garbage(double s, Texture i, double z, int32 ac):
		g_x(0), g_p({ 0,0 }), g_scale(s), g_texture(i), g_time(z), g_hit(false), g_Cut(ac) {};

	Garbage(double x, double s, Texture i, double z, int32 ac):
		g_x(x), g_p({ x,0 }), g_scale(s), g_texture(i), g_time(z), g_hit(false), g_Cut(ac) {};

	void draw() const;
	void putpoints(Vec2 pos);
	void changehitter(double t);
	bool gethitter() const;
	static Array<Garbage> GenerateRandomPoints(const Rect& rect,
		double radius, double size, Texture tex, bool clip = true);

	Circle getcircle();

private:
	double g_x;
	Vec2 g_p;
	double g_scale;
	Texture g_texture;
	double g_time;
	bool g_hit;
	int32 g_Cut;
	Circle g_circle;
};

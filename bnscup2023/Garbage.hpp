#pragma once
#include <Siv3D.hpp>

class Garbage
{
public:
	Garbage(int32 s, Texture t, double z):
		g_p({ 0,0 }), g_s(s), g_texture(t), g_time(z), g_hit(false) {};

	void draw() const;
	void putpoints(Vec2 pos);
	void changepos();
	void changehitter(double t);
	bool gethitter() const;

private:
	Vec2 g_p;
	int32 g_s;
	Texture g_texture;
	double g_time;
	bool g_hit;
};

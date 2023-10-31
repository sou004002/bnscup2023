#pragma once
#include <Siv3D.hpp>
#include "CollisionImage.hpp"

class Garbage : public CollisionImage
{
public:
	Garbage(double s, Image i, double z, int32 ac, Aquarium aq)
		:CollisionImage(0, 0, s, i, aq),
		g_x(0), g_p({ 0,0 }), g_time(z), g_hit(false), g_Cut(ac) {};

	Garbage(double x, double s, Image i, double z, int32 ac, Aquarium aq)
		:CollisionImage({ x, 0 }, s, i, aq),
		g_x(x), g_p({ x,0 }), g_time(z), g_hit(false), g_Cut(ac) {};

	void draw() const override;
	void putpoints(Vec2 pos);
	void changehitter(double t);
	bool gethitter() const;
	static Array<Garbage> GenerateRandomPoints(const Rect& rect,
		double radius, double size, Image tex, Aquarium aq, bool clip = true);

private:

	double g_x;
	Vec2 g_p;
	double g_time;
	bool g_hit;
	int32 g_Cut;
};

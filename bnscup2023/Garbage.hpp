#pragma once
#include <Siv3D.hpp>

class Garbage
{
public:
	Garbage(double s, Texture i, double z, int32 ac):
		g_x(0), g_p({ 0,0 }), g_scale(s), g_texture(i), g_time(z), g_hit(false), g_Cut(ac) {};

	Garbage(double x, double s, Texture i, double z, int32 ac):
		g_x(x), g_p({ x,0 }), g_scale(s), g_texture(i), g_time(z), g_hit(false), g_Cut(ac) {};



	void draw(bool c) const;
	void putpoints(Vec2 pos);
	void changehitter(double t);
	bool gethitter() const;

	static inline  double coolTime = 3.0;
	static inline double time = 0;
	static Array<Garbage> GenerateRandomPoints(const Rect& rect,
		double radius, double size, Texture tex,double speed,bool clip = true);
	Circle getcircle() const;

	void set_del(bool x);
	bool get_del() const ;
	void set_hit(bool x);
	double get_time() const;
	void set_time(double t) ;
	Garbage& operator=(const Garbage&);

private:
	double g_x;
	Vec2 g_p;
	double g_scale;
	Texture g_texture;
	double g_time;
	bool g_hit;//trueだったら表示
	int32 g_Cut;
	Circle g_circle={g_p,50};
	bool g_del = false;
	double m_coolTime = 3.0;
};

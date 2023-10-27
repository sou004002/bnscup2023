#pragma once
#include <Siv3D.hpp>

class Fish
{
public:
	Fish(int32 x, int32 y, int32 s, Texture t, int32 ac)
		:m_p({ x, y }), m_s(s), m_texture(t),
		m_to({ x, y }), m_v({ 0, 0 }), m_time(0.0) ,m_animCnt(ac){};
	Fish(Vec2 p, int32 s, Texture t,int32 ac)
		:m_p(p), m_s(s), m_texture(t),
		m_to(p), m_v({ 0, 0 }), m_time(0.0), m_animCnt(ac) {};

	void draw() const;
	void move();

private:
	Vec2 m_p;
	int32 m_s;
	Texture m_texture;
	Vec2 m_to;
	Vec2 m_v;
	double m_time;
	int32 m_animCnt;
};


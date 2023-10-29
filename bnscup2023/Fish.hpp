#pragma once
#include <Siv3D.hpp>
#include "CollisionImage.hpp"

class Fish : public CollisionImage
{
public:
	Fish(int32 x, int32 y, double s, Image i, int32 ac)
		:CollisionImage(x, y, s, i),
		m_to({ x, y }), m_v({ 0, 0 }), m_time(0.0), m_animNum(ac) {};
	Fish(Vec2 p, double s, Image i, int32 ac)
		:CollisionImage(p, s, i),
		m_to(p), m_v({ 0, 0 }), m_time(0.0), m_animNum(ac) {};

	void draw() const override;
	void move();

private:
	Vec2 m_to;
	Vec2 m_v;
	double m_time;
	int32 m_animNum;
	int32 m_speed = 250;
};

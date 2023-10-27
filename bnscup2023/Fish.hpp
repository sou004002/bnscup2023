#pragma once
#include <Siv3D.hpp>
#include "CollisionImage.hpp"

class Fish : public CollisionImage
{
public:
	Fish(int32 x, int32 y, double w, Image i, int32 ac, Aquarium aq)
		:CollisionImage(x, y, w*2, i, aq),
		m_to({ x, y }), m_v({ 0, 0 }), m_time(0.0), m_animNum(ac) {};
	Fish(Vec2 p, double w, Image i, int32 ac, Aquarium aq)
		:CollisionImage(p, w*2, i, aq),
		m_to(p), m_v({ 0, 0 }), m_time(0.0), m_animNum(ac) {};

	void draw() const override;
	void move();
	bool isCollision(const CollisionImage& ci) const;

private:
	Vec2 m_to;
	Vec2 m_v;
	double m_time;
	int32 m_animNum;
	int32 m_speed = 250;
};

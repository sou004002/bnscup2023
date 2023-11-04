#pragma once
#include <Siv3D.hpp>
#include "CollisionImage.hpp"

class Fish : public CollisionImage
{
public:
	Fish(int32 x, int32 y, double w, Texture t, int32 ac, Aquarium aq)
		:CollisionImage(x, y, w * 2, t, aq),
		m_to({ x, y }), m_v({ 0, 0 }), m_time(0.0), m_animNum(ac),
		m_circle({ 0, 0, m_width / 8 }), m_circleCenter({ x + m_width / 16, y + m_height / 2 }) {};
	Fish(Vec2 p, double w, Texture t, int32 ac, Aquarium aq)
		:CollisionImage(p, w * 2, t, aq),
		m_to(p), m_v({ 0, 0 }), m_time(0.0), m_animNum(ac),
		m_circle({ 0, 0, m_width / 8 }), m_circleCenter({ p.x + m_width / 16, p.y + m_height / 2 }) {};

	void draw() const override;
	void move();
	bool isCollision(const CollisionImage& ci) const;
	Circle getCircle() { return m_circle; }

private:
	Vec2 m_to;
	Vec2 m_v;
	double m_time;
	int32 m_animNum;
	int32 m_speed = 250;
	Circle m_circle;
	Vec2 m_circleCenter;
};

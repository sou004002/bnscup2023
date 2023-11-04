#pragma once
#include <Siv3D.hpp>
#include "CollisionImage.hpp"

class JerryFish : public CollisionImage
{
public:
	JerryFish(int32 x, int32 y, double w, Texture t, int32 ac, Aquarium aq)
		:CollisionImage(x, y, w * ac, t, aq),
		m_to({ x, y }), m_v({ 0, 0 }), m_time(0.0), m_animNum(ac),
		m_circle({ 0, 0, m_width / (2 * ac), m_width / ac }),
		m_circleCenter({ x + m_width / (2 * ac), y + m_height / 2}) {};

	void draw() const override;
	void move();
	void move(Vec2 to);
	bool isCollision(const CollisionImage& ci) const;

	static inline double interval = 1.0;

private:
	Vec2 m_to;
	Vec2 m_v;
	double m_time;
	int32 m_animNum;
	int32 m_speed = 250;
	Ellipse m_circle;
	Vec2 m_circleCenter;
};


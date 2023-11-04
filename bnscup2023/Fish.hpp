#pragma once
#include <Siv3D.hpp>
#include "CollisionImage.hpp"

class Fish : public CollisionImage
{
public:
	Fish(int32 x, int32 y, double w, Texture t, int32 ac, Aquarium aq)
		:CollisionImage(x, y, w * ac, t, aq),
		m_to({ x, y }), m_v({ 0, 0 }), m_time(0.0), m_animNum(ac),
		m_circle({ 0, 0, m_width / (4 * ac) }),
		m_circleCenter({ x + m_width / (8 * ac), y + m_height / 2 }) {};
	/*
	Fish(const Fish& c)
		:CollisionImage(c.getPoint().x, c.getPoint().y,c.getWidth()*c.getAnimNum(),
			)
	{};
	*/

	void draw() const override;
	void move();
	void move(Vec2 to);
	bool isCollision(const CollisionImage& ci) const;

	Vec2 getTo() const { return m_to; }
	Vec2 getV() const { return m_v; }
	double getTime() const { return m_time; }
	int32 getAnimNum() const { return m_animNum; }
	Circle getCircle() const { return m_circle; }
	Vec2 getCircleCenter() const { return m_circleCenter; }


	static inline double interval = 1.0;

private:
	Vec2 m_to;
	Vec2 m_v;
	double m_time;
	int32 m_animNum;
	int32 m_speed = 250;
	Circle m_circle;
	Vec2 m_circleCenter;
};

#pragma once
#include<Siv3D.hpp>
#include"Aquarium.hpp"

class CollisionImage
{
public:
	CollisionImage(int32 x, int32 y, double w, Texture t, Aquarium aq)
		:m_point({ x, y }), m_scale(w / t.width()),
		m_width(w), m_height(m_scale* t.height()), m_texture(t),
		m_aquarium(aq), m_circle({ 0, 0, m_width / 2 }), m_circleCenter({ 0, 0 }) {};
	CollisionImage(Vec2 p, double w, Texture t, Aquarium aq)
		:m_point(p), m_scale(w / t.width()),
		m_width(w), m_height(m_scale* t.height()), m_texture(t),
		m_aquarium(aq), m_circle({ 0, 0, m_width / 2 }), m_circleCenter({ 0, 0 }) {};
	CollisionImage(const CollisionImage& c)
		:m_point(c.getPoint()), m_scale(c.getScale()),
		m_width(c.getWidth()), m_height(c.getHeight()), m_texture(c.getTexture()),
		m_circle(c.getCircle()), m_circleCenter(c.getCircleCenter()),
		m_aquarium(c.getAquarium()){};

	virtual void draw() const;
	bool isCollision(const CollisionImage& ci) const;
	void move(Vec2 v);

	Vec2 getPoint() const { return m_point; }
	double getScale() const { return m_scale; }
	double getWidth() const { return m_width; }
	double getHeight() const { return m_height; }
	Texture getTexture() const { return m_texture; }
	Aquarium getAquarium() const { return m_aquarium; }
	Circle getCircle() const { return m_circle; }
	Vec2 getCircleCenter() const { return m_circleCenter; }

	void setTexture(Texture t) { m_texture = t; }

protected:
	Vec2 m_point;
	double m_scale;
	double m_width;
	double m_height;
	Texture m_texture;
	Aquarium m_aquarium;
	Circle m_circle;
	Vec2 m_circleCenter;
};

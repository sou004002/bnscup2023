#pragma once
#include<Siv3D.hpp>
#include"Aquarium.hpp"

class CollisionImage
{
public:
	CollisionImage(int32 x, int32 y, double w, Image i, Aquarium aq)
		:m_point({ x, y }), m_scale(w / i.width()),
		m_width(w), m_height(m_scale* i.height()), m_texture(i),
		m_polygon(i.alphaToPolygon(1, AllowHoles::No).simplified(35.0)),
		m_aquarium(aq) {};
	CollisionImage(Vec2 p, double w, Image i, Aquarium aq)
		:m_point(p), m_scale(w / i.width()),
		m_width(w), m_height(m_scale* i.height()), m_texture(i),
		m_polygon(i.alphaToPolygon(1, AllowHoles::No).simplified(35.0)),
		m_aquarium(aq) {};
	CollisionImage(const CollisionImage& c)
		:m_point(c.getPoint()), m_scale(c.getScale()),
		m_width(c.getWidth()), m_height(c.getHeight()), m_texture(c.getTexture()),
		m_polygon(c.getPolygon()), m_aquarium(c.getAquarium()) {};

	virtual void draw() const;
	bool isCollision(const CollisionImage& ci) const;
	void move(Vec2 v);

	Vec2 getPoint() const { return m_point; }
	double getScale() const { return m_scale; }
	double getWidth() const { return m_width; }
	double getHeight() const { return m_height; }
	Texture getTexture() const { return m_texture; }
	Polygon getPolygon() const { return m_polygon; }
	Aquarium getAquarium() const { return m_aquarium; }

protected:
	Vec2 m_point;
	double m_scale;
	double m_width;
	double m_height;
	Texture m_texture;
	Polygon m_polygon;
	Aquarium m_aquarium;
};

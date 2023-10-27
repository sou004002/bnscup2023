#pragma once
#include<Siv3D.hpp>

class CollisionImage
{
public:
	CollisionImage(int32 x, int32 y, double s, Image i)
		:m_point({ x, y }), m_scale(s), m_texture(i),
		m_polygon(i.alphaToPolygon(1, AllowHoles::No).simplified(4.0)) {};
	CollisionImage(Vec2 p, double s, Image i)
		:m_point(p), m_scale(s), m_texture(i),
		m_polygon(i.alphaToPolygon(1, AllowHoles::No).simplified(4.0)) {};

	virtual void draw() const;
	bool isCollision(const CollisionImage& ci) const;

	Vec2 getPoint() const { return m_point; }
	double getScale() const { return m_scale; }
	Polygon getPolygon() const { return m_polygon; }

protected:
	Vec2 m_point;
	double m_scale;
	Texture m_texture;
	Polygon m_polygon;
};

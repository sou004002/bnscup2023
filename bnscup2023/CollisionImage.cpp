#include "stdafx.h"
#include "CollisionImage.hpp"

void CollisionImage::draw() const
{
	//　当たり判定がどこにあるか表示
	//m_circle.movedBy(m_circleCenter)
	//	.draw(ColorF{ 1.0, 1.0, 0.0, 0.2 })
	//	.drawFrame(2, Palette::Yellow);

	m_texture.scaled(m_scale).draw(m_point);
	//m_circle.draw().movedBy(m_point);
}

bool CollisionImage::isCollision(const CollisionImage& ci) const
{
	//　当たり判定がどこにあるか表示
	m_polygon.scaled(m_scale).movedBy(m_point)
		.draw(ColorF{ 1.0, 1.0, 0.0, 0.2 })
		.drawWireframe(2, Palette::Yellow);
	ci.getPolygon().scaled(ci.getScale()).movedBy(ci.getPoint())
		.draw(ColorF{ 0.0, 1.0, 1.0, 0.2 })
		.drawWireframe(2, Palette::Red);

	return m_polygon.scaled(m_scale).movedBy(m_point)
		.intersects(ci.getPolygon().scaled(ci.getScale()).moveBy(ci.getPoint()));
}

void CollisionImage::move(Vec2 v)
{
	m_point = v;
	m_circleCenter = v;
}


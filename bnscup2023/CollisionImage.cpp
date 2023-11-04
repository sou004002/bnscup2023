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
	return m_circle.movedBy(m_circleCenter)
		.intersects(ci.getCircle().moveBy(ci.getCircleCenter()));
}

void CollisionImage::move(Vec2 v)
{
	m_point = v;
	m_circleCenter = v;
}


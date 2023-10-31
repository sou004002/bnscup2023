#include "stdafx.h"
#include "Fish.hpp"

double interval = 1.0;

void Fish::move()
{
	Polygon scaledPolygon = m_polygon.scaled(m_scale);
	double offsetX = scaledPolygon.outer().map(
			[](const Vec2& a) {return a.x; }).sorted().front();
	double offsetY = scaledPolygon.outer().map(
		[](const Vec2& a) {return a.y; }).sorted().front();

	const RectF tank = m_aquarium._frame.stretched(-m_width / 8, -m_height / 4)
		.movedBy(-m_width / 8 - offsetX, -m_height / 4 - offsetY).scaled(0.9);
	tank.drawFrame(2, 2, Palette::Orange);
	Circle(m_point, 5).draw(Palette::Forestgreen);
	//　当たり判定がどこにあるか表示
	scaledPolygon.movedBy(m_point)
		.draw(ColorF{ 1.0, 1.0, 0.0, 0.2 })
		.drawWireframe(2, Palette::Yellow);

	m_time += Scene::DeltaTime();
	if (interval <= m_time)
	{
		m_to = RandomVec2(tank);
		m_time -= interval;
		interval = Random(0.3, 7.0);
	}
	m_point = Math::SmoothDamp(m_point, m_to, m_v, 1.0);
}

bool Fish::isCollision(const CollisionImage& ci) const
{
	//　当たり判定がどこにあるか表示
	//m_polygon.scaled(m_scale).movedBy(m_point)
	//	.draw(ColorF{ 1.0, 1.0, 0.0, 0.2 })
	//	.drawWireframe(2, Palette::Yellow);
	//ci.getPolygon().scaled(ci.getScale()).movedBy(ci.getPoint())
	//	.draw(ColorF{ 0.0, 1.0, 1.0, 0.2 })
	//	.drawWireframe(2, Palette::Red);

	return m_polygon.scaled(m_scale).movedBy(m_point)
		.intersects(ci.getPolygon().scaled(ci.getScale()).moveBy(ci.getPoint()));
}

void Fish::draw() const
{
	const uint64 t = Time::GetMillisec();
	const int32 x = (t / m_speed % m_animNum);
	m_texture(x * (m_texture.width() / m_animNum),
		0, m_texture.width() / m_animNum, m_texture.height())
		.mirrored(0 < m_v.x).scaled(m_scale).draw(m_point);
}

Texture Fish::getTexture()
{
	return m_texture;

}

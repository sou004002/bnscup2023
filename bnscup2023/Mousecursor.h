#pragma once
#include "CollisionImage.hpp"
#include "Food.h"
#include <Siv3D.hpp>

class Mousecursor
{
public:
	Mousecursor(double x, double y, Image otete, Image ami, Image allow, Aquarium aq)
		:m_x(x), m_y(y), m_feed(true), m_pickGarbage(false),
		m_otete(m_x, m_y, 50.0, otete, aq),
		m_net(m_x, m_y, 70.0, ami, aq),
		m_allow(m_x, m_y, 60.0, allow, aq),
		m_image(m_x, m_y, 50.0, otete, aq)
	{
		/*m_x = x;
		m_y = y;
		m_feed = true;
		m_pickGarbage = false;
		CollisionImage m_otete((int32)m_x, (int32)m_y, 1.0, Image{ U"dotImages/cursor.svg" });
		CollisionImage m_net((int32)m_x, (int32)m_y, 1.0, Image{ U"dotImages/ami.svg" });
		CollisionImage m_allow((int32)m_x, (int32)m_y, 1.0, Image{ U"dotImages/tatsu.svg" });
		m_image = m_otete;*/
	};
	double m_x;
	double m_y;
	CollisionImage m_image;
	CollisionImage m_net;
	CollisionImage m_allow;
	CollisionImage m_otete;
	bool m_feed;
	bool m_pickGarbage;
	void move(double min, double max, double maxY);
	void draw() const;
};


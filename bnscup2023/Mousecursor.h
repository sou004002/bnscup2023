#pragma once
#include "CollisionImage.hpp"
#include "Food.h"
#include <Siv3D.hpp>
class Mousecursor
{
public:
	Mousecursor(float x, float y, Aquarium aq)
		:m_x(x), m_y(y), m_feed(true), m_pickGarbage(false),
		m_otete((int32)m_x, (int32)m_y, 0.3, Image{ U"dotImages/turtle-s_16_0.svg" }, aq),
		m_net((int32)m_x, (int32)m_y, 0.2, Image{ U"dotImages/ami.svg" }, aq),
		m_allow((int32)m_x, (int32)m_y, 0.3, Image{ U"dotImages/tatsu.svg" }, aq),
		m_image((int32)m_x, (int32)m_y, 0.3, Image{ U"dotImages/turtle-s_16_0.svg" }, aq)
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
	float m_x;
	float m_y;
	CollisionImage m_image;
	CollisionImage m_net;
	CollisionImage m_allow;
	CollisionImage m_otete;
	bool m_feed;
	bool m_pickGarbage;
	void move(float min, float max, float maxY);
	void draw();
};


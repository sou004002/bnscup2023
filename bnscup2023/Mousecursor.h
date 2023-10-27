#pragma once
#include "CollisionImage.hpp"
#include "Food.h"
#include <Siv3D.hpp>
class Mousecursor
{
public:
	Mousecursor(float x, float y) {
		m_x = x;
		m_y = y;
		m_feed = true;
		m_pickGarbage = false;
		m_image= m_otete;
		m_otete(m_x, m_y, size, Image{ U"dotImages/cursor.svg" });
		m_net(m_x, m_y, size, Image{ U"dotImages/ami.svg" });
		m_net(m_x, m_y, size, Image{ U"dotImages/tatsu.svg" });
			//こんな感じで全部Collisionクラスに差し替える。
	}
	float m_x;
	float m_y;
	CollisionImage m_image;
	CollisionImage m_net;
	CollisionImage m_allow;
	CollisionImage m_otete;
	bool m_feed;
	bool m_pickGarbage;
	void move(float min, float max, float maxY);
	void draw() const;
};


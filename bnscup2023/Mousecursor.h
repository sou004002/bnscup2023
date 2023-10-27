#pragma once
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
		m_texture = m_otete;
	}
	float m_x;
	float m_y;
	Texture m_texture;
	Texture m_otete{ U"🤏"_emoji };
	Texture m_net{ U"dotImages/ami.svg" };
	Texture m_allow{ U"🔎"_emoji };
	bool m_feed;
	bool m_pickGarbage;
	void move(float min, float max, float maxY);
	void draw() const;
};


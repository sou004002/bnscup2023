#pragma once
#include "Food.h"
#include <Siv3D.hpp>
class Mousecursor
{
public:
	Mousecursor(float x, float y) {
		this->x = x;
		this->y = y;
		feed = true;
		pickGarbage = false;
		texture = otete;
	}
	float x;
	float y;
	Texture texture;
	Texture otete{ U"🤏"_emoji };
	Texture net{ U"dotImages/ami.svg" };
	Texture allow{ U"🔎"_emoji };
	bool feed;
	bool pickGarbage;
	void move(float min, float max, float maxY);
	void draw() const;
};


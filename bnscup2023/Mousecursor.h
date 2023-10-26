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
	Texture otete{ U"🍬"_emoji };
	Texture net{ U"🍟"_emoji };
	Texture allow{ U"🥐"_emoji };
	bool feed;
	bool pickGarbage;
	void move();
	void draw() const;
	Food generate(float x);
};


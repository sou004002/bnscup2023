#pragma once
#include "Food.h"
#include <Siv3D.hpp>
class Mousecursor
{
public:
	Mousecursor(float x, float y) {
		this->x = x;
		this->y = y;
		esa = true;
		gomi = false;
		texture = otete;
	}
	float x;
	float y;
	Texture texture;
	Texture otete{ U"🍬"_emoji };
	Texture ami{ U"🍟"_emoji };
	Texture yajirusi{ U"🥐"_emoji };
	bool esa;
	bool gomi;
	void move();
	void draw() const;
	Food generate(float x);
};


#pragma once
#include<Siv3D.hpp>

class Food {
public:
	Food(float x) {
		this->x = x;
		this->y = 60;
		texture = esaesa;
	};
	void draw() const;
	void move();

	float x;
	float y;
	Texture texture;
	const Texture esaesa{ U"🍙"_emoji };
};

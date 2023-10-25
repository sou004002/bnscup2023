﻿#pragma once
#include<Siv3D.hpp>

class Food {
public:
	Food(float x) {
		this->x = x;
		this->y = 60;
		texture = esaesa;
		trash_time = 0;
		graund = false;
	};
	void draw() const;
	void move();

	float x;
	float y;
	bool graund;
	float trash_time;
	Texture texture;
	const float dy = 2.7;
	const Texture esaesa{ U"🍙"_emoji };
};

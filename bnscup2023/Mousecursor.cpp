#include "Mousecursor.h"

void Mousecursor::move() {
	if (feed) {
		x = Cursor::Pos().x;
		if (x <= 300) x = 300;
		if (x >= 700) x = 700;
		y = 50;
	}
	else if (pickGarbage) {
		x = Cursor::Pos().x;
		y = Cursor::Pos().y;
		if (300 <= x && x <= 700 && 150 <= y && y <= 600) {
			texture = net;
		}
		else {
			texture = allow;
		}
	}
}

void Mousecursor::draw() const {
	texture.scaled(0.3).drawAt(x, y);
}

Food Mousecursor::generate(float x) {
	Food food(x);
	return food;
}

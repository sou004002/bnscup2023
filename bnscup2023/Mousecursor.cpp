#include "Mousecursor.h"

void Mousecursor::move(float min, float max , float maxY) {
	if (feed) {
		x = Cursor::Pos().x;
		if (x <= min) x = min;
		if (x >= max) x = max;
		y = 50;//投下位置（y座標）
	}
	else if (pickGarbage) {
		x = Cursor::Pos().x;
		y = Cursor::Pos().y;
		if (min <= x && x <= max && 150 <= y && y <= maxY) {//ここの数字は水面の高さ
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


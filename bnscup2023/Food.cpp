#include "Food.h"

void Food::move(){
	if (RandomBool()) {
		x += 1;
	} else {
		x -= 1;
	}
	y = y + dy;
	if (y >= 600) {
		y = 590;
		graund = true;
	}
	if (graund) {
		trash_time += Scene::DeltaTime();
	}
	if (trash_time >= 100) {
		//この餌の座標からゴミを生成。餌をdelete
	}
}

void Food::draw() const {
	texture.scaled(0.1).drawAt(x, y);
}

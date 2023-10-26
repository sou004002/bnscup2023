#include "Food.h"

void Food::move(){
	elapsedTime += Scene::DeltaTime();
	if (!graund) {
		x += Periodic::Sine1_1(2s, Scene::Time()+startTime);
		if (elapsedTime >= 0.5) {
			if (RandomBool()) {
				x += 1;
			}
			else {
				x -= 1;
			}
			elapsedTime -= 0.5;
		}
		x = fmax(x, 305);
		x = fmin(x, 695);
	}
	y = y + dy;
	if (y >= 590) {
		y = 590;
		graund = true;
	}
	if (graund) {
		trash_time += Scene::DeltaTime();
	}
}

void Food::draw() const {
	texture.scaled(0.1).drawAt(x, y);
}

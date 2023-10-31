#include "Food.h"

void Food::move() {
	m_elapsedTime += Scene::DeltaTime();
	if (!m_ground) {
		m_x += Periodic::Sine1_1(2s, Scene::Time() + m_startTime);
		if (m_elapsedTime >= 0.5) {//餌がランダムな横揺れを起こす間隔
			if (RandomBool()) {
				m_x += 1;
			}
			else {
				m_x -= 1;
			}
			m_elapsedTime -= 0.5;
		}
		m_x = fmax(m_x, m_left + 5); //水槽の左端＋マージン
		m_x = fmin(m_x, m_right - 5);
	}
	m_y = m_y + m_dy;
	m_esaesa.move(Vec2({ m_x, m_y }));
	if (m_y >= m_maxY - 10) {//10はマージン
		m_y = m_maxY - 10;
		m_ground = true;
	}
	if (m_ground) {
		m_trashTime += Scene::DeltaTime();
	}
}

void Food::eaten(Fish fish)
{
	if (m_esaesa.isCollision(fish)) {

	}
}

Food& Food::operator=(const Food& food)
{
	m_x = food.m_x;
	m_y = food.m_y;
	m_ground = food.m_ground;
	m_startTime = food.m_startTime;
	m_trashTime = food.m_trashTime;
	m_elapsedTime = food.m_elapsedTime;
	m_maxY = food.m_maxY;
	m_left = food.m_left;
	m_right = food.m_right;
	return *this;
}

void Food::draw() const {
	m_esaesa.draw();
}

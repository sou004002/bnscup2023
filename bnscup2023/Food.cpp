#include "Food.h"

void Food::move(){
	m_elapsedTime += Scene::DeltaTime();
	if (!m_ground) {
		m_x += Periodic::Sine1_1(2s, Scene::Time()+m_startTime);
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
	if (m_y >= m_maxY - 5) {//5はマージン
		m_y = m_maxY - 5;
		m_ground = true;
	}
	if (m_ground) {
		m_trashTime += Scene::DeltaTime();
	}
}

void Food::removal()
{
	
}

void Food::draw() const {
	m_texture.scaled(0.1).drawAt(m_x, m_y);
}

#include "Mousecursor.h"

void Mousecursor::move(double min, double max, double maxY) {
	if (m_feed) {
		m_x = Cursor::Pos().x;
		if (m_x <= min) m_x = min;
		if (m_x >= max) m_x = max;
		m_y = 50;//投下位置（y座標）
	}
	else if (m_pickGarbage) {
		m_x = Cursor::Pos().x;
		m_y = Cursor::Pos().y;
		if (min <= m_x && m_x <= max && 150 <= m_y && m_y <= maxY) {//ここの数字は水面の高さ
			m_image = m_net;
		}
		else {
			m_image = m_allow;
		}
	}
	m_image.move(Vec2({ m_x, m_y }));
}

void Mousecursor::draw() const{
	m_image.draw();
}


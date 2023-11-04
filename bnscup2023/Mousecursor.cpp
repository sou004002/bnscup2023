﻿#include "Mousecursor.h"

void Mousecursor::move(double min, double max, double maxY) {
	if (m_feed) {
		m_x = Cursor::Pos().x-15;//15はズレの修正
		if (m_x <= min) m_x = min;
		if (m_x >= max) m_x = max;
		m_y = 100;//投下位置（y座標）
	}
	else if (m_pickGarbage) {
		m_x = Cursor::Pos().x - 17;//画像の位置微調整
		m_y = Cursor::Pos().y - 42;
		if (min <= m_x && m_x <= max && 150 <= m_y && m_y <= maxY) {//ここの数字は水面の高さ
			m_image = m_net;
		}
		else {
			m_image = m_allow;
		}
		if (m_image.getScale() == m_allow.getScale()) {
			m_x -= 5;
			m_y += 28;
		}
	}
	m_image.move(Vec2({ m_x, m_y }));
}

void Mousecursor::draw() const{
	m_image.draw();
}


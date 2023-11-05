#include "stdafx.h"
#include "FoodBtn.hpp"



Vec2 FoodBtn::getPos() {
	return m_p;
}



void FoodBtn::update() {
	const bool mouseOver = m_rect.mouseOver();


	if (m_rect.leftClicked() || MouseR.down())
	{
		AudioAsset(U"foodBtn").playOneShot();
		m_pressed = !m_pressed;
	}
}
void FoodBtn::draw() const{
	if (m_pressed) {
		m_texture(m_texture.width() / 2, 0, m_texture.width() / 2, m_texture.height()).scaled(m_s).draw(m_p);

	}
	else {
		m_texture(0, 0, m_texture.width() / 2, m_texture.height()).scaled(m_s).draw(m_p);
	}
		m_rect.drawFrame(3,ColorF{0,0,0,0});
}

bool FoodBtn::getPressed() const{
	return m_pressed;
}

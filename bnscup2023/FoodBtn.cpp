#include "stdafx.h"
#include "FoodBtn.hpp"
//


Vec2 FoodBtn::getPos() {
	return m_p;
}



bool FoodBtn::update() {
	const bool mouseOver = m_rect.mouseOver();

	bool pushed = false;
	if (mouseOver)
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}
	if (not m_pressed) {
		if (m_rect.leftClicked())
		{
			m_pressed = true;
		}
	}
	else {
		if (m_rect.leftReleased()) {
			m_pressed = false;
			pushed = true;
		}
		else if (not m_rect.mouseOver())
		{
			m_pressed = false;
		}
	}
	m_transitionPressed.update(m_pressed);

	return pushed;
}
void FoodBtn::draw(){
	if (update()) {
		m_texture(m_texture.width() / 2, 0, m_texture.width() / 2, m_texture.height()).scaled(m_s).draw(m_p);
		m_rect.drawFrame(3);
	}
	else {
		m_texture(0, 0, m_texture.width() / 2, m_texture.height()).scaled(m_s).draw(m_p);
		m_rect.drawFrame(3);
	}
}
bool FoodBtn::click() {
	double t = 0;
	if (m_rect.leftClicked()) {
		if (Scene::Time() - t > 2) {
			m_pressed = !m_pressed;
			t = Scene::Time();
		}
	}
	return m_pressed;
}

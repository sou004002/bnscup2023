#include "stdafx.h"
#include "FoodBtn.hpp"

void FoodBtn::draw() const {
	if (m_isFood) {
		m_texture(m_texture.width()/2,0,m_texture.width()/2,m_texture.height()).resized(m_s).draw(m_p);
	}
	else {
		m_texture(0, 0, m_texture.width() / 2, m_texture.height()).scaled(m_s).draw(m_p);
	}
}

bool FoodBtn::getIsFood() {
	return m_isFood;
}

bool FoodBtn::getEnabled() {
	return m_enabled;
}

void FoodBtn::setEnabled() {
	m_enabled = !m_enabled;
}

Vec2 FoodBtn::getPos() {
	return m_p;
}

void FoodBtn::click() {
	m_isFood = !m_isFood;
	m_enabled = false;
}

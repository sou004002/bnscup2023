#include "stdafx.h"
#include "HPBar.hpp"

void HPBar::draw(const RectF& rect) const{
	const RectF rectHP{ rect.pos, (rect.w * getHPRatio()), rect.h };
	rect.draw(m_backgroundColor);
	rectHP.rounded(40).draw(m_hpColor);
	rect.drawFrame(m_frameThickness, m_frameColor);
}

int32 HPBar::getHP() const {
	return m_currentHP;
}

int32 HPBar::getMaxHP() const {
	return m_maxHP;
}

double HPBar::getHPRatio() const {
	return (static_cast<double>(m_currentHP) / m_maxHP);
}

void HPBar::setHP(int32 hp) {
	m_currentHP = Clamp(hp, 0, m_maxHP);
}

void HPBar::damage(int32 damage) {
	m_currentHP = Clamp((m_currentHP - damage), 0, m_maxHP);
}

void HPBar::heal(int32 heal) {
	setHP(m_currentHP + heal);
}

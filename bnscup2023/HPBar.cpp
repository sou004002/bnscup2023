#include "stdafx.h"
#include "HPBar.hpp"

void HPBar::draw(const Rect& rect) const{
	const RectF rectHP{ rect.pos, (rect.w * getHPRatio()), rect.h };
	rect.draw(m_backgroundColor);
	rectHP.draw(m_hpColor);

	//ドット絵風の枠を描く
	Rect{rect.pos.x,rect.pos.y-m_frameThickness,rect.w,m_frameThickness}.draw();
	Rect{ rect.pos.x,rect.pos.y+rect.h,rect.w,m_frameThickness }.draw();
	Rect{ rect.pos.x-m_frameThickness,rect.pos.y,m_frameThickness,rect.h }.draw();
	Rect{ rect.pos.x +rect.w,rect.pos.y,m_frameThickness,rect.h }.draw();

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

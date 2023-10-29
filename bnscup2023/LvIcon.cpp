#include "stdafx.h"
#include "LvIcon.hpp"

void LvIcon::draw() const{
	m_texture.scaled(m_s).draw(m_p);
	m_font(U"Lv.").draw(m_s*80,m_p.x+8,m_p.y+43);
	if (m_level < 10) {
		m_font(U" ",m_level).draw(m_s * 150, m_p.x + 48, m_p.y + 23);
	}
	else {
		m_font(m_level).draw(m_s * 150, m_p.x + 48, m_p.y + 23);
	}
}

int32 LvIcon::getLevel() const {
	return m_level;
}

void LvIcon::levelUp(){
	m_level++;
}

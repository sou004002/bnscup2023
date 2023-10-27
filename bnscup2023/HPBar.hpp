#pragma once
#include <Siv3D.hpp>

class HPBar
{
public:
	HPBar(ColorF bgColor, ColorF hpColor, ColorF frameColor, double frameThickness, int32 maxHP, int32 currentHP)
		:m_backgroundColor(bgColor), m_hpColor(hpColor), m_frameColor(frameColor),
		m_frameThickness(frameThickness), m_maxHP(maxHP), m_currentHP(currentHP) {};
	HPBar(ColorF hpColor,   int32 maxHP, int32 currentHP)
		:m_hpColor(hpColor),m_maxHP(maxHP), m_currentHP(currentHP) {};

	void draw(const RectF& rect) const;
	int32 getHP() const;
	int32 getMaxHP() const;
	double getHPRatio() const;
	void setHP(int32 hp);
	void damage(int32 damage);
	void heal(int32 heal);


private:
	ColorF m_backgroundColor{ 0.6 };
	ColorF m_hpColor;
	ColorF m_frameColor{ 1.0 };
	double m_frameThickness=1.5;
	int32 m_maxHP = 1;
	int32 m_currentHP = 1;
	

};

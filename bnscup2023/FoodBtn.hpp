#pragma once
#include <Siv3D.hpp>

class FoodBtn
{
public:
		Timer m_interval{2s};
	FoodBtn(Vec2 p, double s)
		:m_p(p), m_s(s), m_isFood(false),m_enabled(true) {};
	FoodBtn(int32 x,int32 y, double s)
		:m_p({x,y}), m_s(s), m_isFood(false),m_enabled(true) {};
	void draw() const;
	bool getIsFood();
	bool getEnabled();
	void setEnabled();
	Vec2 getPos();
	void click();

private:
	Vec2 m_p;
	double m_s;
	Texture m_texture{ U"dotImages/foodBtn.svg" };
	bool m_isFood;//押しているかどうか
	bool m_enabled;//押せるかどうか



};

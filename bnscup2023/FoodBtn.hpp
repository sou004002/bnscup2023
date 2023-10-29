#pragma once
#include <Siv3D.hpp>

class FoodBtn
{
public:
	FoodBtn(Vec2 p, double s)
		:m_p(p), m_s(s),m_pressed(false){};
	FoodBtn(int32 x,int32 y, double s)
		:m_p({x,y}), m_s(s), m_pressed(false){};
	void draw();

	Vec2 getPos();
	bool click();
	bool update();
	

private:
	Vec2 m_p;
	double m_s;
	Texture m_texture{ U"dotImages/foodBtn.svg" };
	Rect m_rect{0,0,100,100};
	Transition m_transitionPressed{ 1.0s,1.0s };
	bool m_pressed = false;
};

#pragma once
#include <Siv3D.hpp>

class FoodBtn
{
public:
	FoodBtn(Vec2 p, double s)
		:m_p(p), m_s(s),m_pressed(false){};
	FoodBtn(int32 x,int32 y, double s)
		:m_p({x,y}), m_s(s), m_pressed(false){};
	void draw() const;

	Vec2 getPos();
	bool getPressed() const;
	void update();
	Rect getRect() const{ return m_rect; }
	

private:
	Vec2 m_p;
	double m_s;
	bool m_pressed;
	Texture m_texture{ U"dotImages/foodBtn.svg" };
	Rect m_rect{(int32)m_p.x,(int32)m_p.y,(int32)(m_texture.width()*m_s)/2,(int32)(m_texture.height() * m_s)};
};

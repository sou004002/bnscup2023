#pragma once
#include <Siv3D.hpp>

class LvIcon
{
public:
	LvIcon(Vec2 p,double s,int32 level)
		:m_p(p),m_s(s), m_level(level) {};

	void draw() const;
	int32 getLevel() const;
	void levelUp();



private:
	Vec2 m_p;
	double m_s;
	Texture m_texture{ U"dotImages/LvIcon.svg" };
	Font m_font{ FontMethod::MSDF, 30 ,U"example/font/INVASION2000.TTF", FontStyle::Bitmap };
	int32 m_level=1;

};

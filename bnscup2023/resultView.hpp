﻿#pragma once
#include <Siv3D.hpp>

class resultView
{
public:
	resultView(int32 level,Texture img)
		:m_level(level) ,m_tex(img){};
	Rect getRetryRect();
	Rect getTitleRect();
	void update(int32 level);
	void draw();

private:
	int32 m_level;
	double m_s=0.5;
	Texture m_tex;
	Rect m_retryRect{0,0,20,20};
	Rect m_titleRect{20,20,20,20};
	Font m_font{ FontMethod::MSDF, 30 ,U"example/font/INVASION2000.TTF", FontStyle::Bitmap };


};

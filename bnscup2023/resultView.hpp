#pragma once
#include <Siv3D.hpp>

class resultView
{
public:
	resultView(int32 level,Texture img,String texName)
		:m_level(level) ,m_tex(img),m_texName(texName){};
	Rect getRetryRect();
	Rect getTitleRect();
	void update(int32 level,Texture tex);
	void draw() const;
	bool getRetryPressed();
	bool getTitlePressed();

private:
	int32 m_level;
	double m_s=0.5;
	Texture m_tex;
	//Rect m_retryRect{ Arg::center((int)600/ 4 + (int)Scene::Width() / 2 - m_retryRect.w / 2 , (int)Scene::Height() / 2 + 350),200,70};
	Rect m_retryRect{ Arg::center((int)Scene::Width() / 2 -150 ,460),200,70 };
	Rect m_titleRect{ Arg::center((int)Scene::Width() / 2 + 150 ,460),200,70 };
	Font m_font{ FontMethod::MSDF, 30 ,U"example/font/INVASION2000.TTF", FontStyle::Bitmap };
	bool m_retryPressed = false;
	bool m_titlePressed = false;
	String m_texName;
	Transition m_retryTransition{ 0.4s,0.2s };
	Transition m_titleTransition{ 0.4s,0.2s };



};

#include "stdafx.h"
#include "resultView.hpp"

Rect resultView::getRetryRect() const{
	Rect retryRect{ Arg::center((int)Scene::Width() / 2 - 150 ,460),200,70 };
	return retryRect;
}
Rect resultView::getTitleRect() const{
	Rect titleRect{ Arg::center((int)Scene::Width() / 2 + 150 ,460),200,70 };
	return titleRect;
}

void resultView::draw() const{
	Rect retryRect{ Arg::center((int)Scene::Width() / 2 - 150 ,460),200,70 };
	Rect titleRect{ Arg::center((int)Scene::Width() / 2 + 150 ,460),200,70 };
	const int32 frameThickness = 20;
	Rect mainView{ Arg::center((int)Scene::Width() / 2,(int)Scene::Height() / 2),600,450 };
	mainView.draw(ColorF{ 0.15 });
	Rect mainViewFrame{ Arg::center((int)Scene::Width() / 2,(int)Scene::Height() / 2),620,470 };
	mainViewFrame.drawFrame(frameThickness, ColorF{ 0 });
	m_font(U"Result").drawAt(60, (int)mainView.w / 2 + mainView.x, (int)mainView.y + 40);
	Line{ (int)mainView.x+30, (int)mainView.y+100, (int)mainView.x + mainView.w-30,  (int)mainView.y + 100 }.draw(LineStyle::SquareDot, 12, Palette::White);
	m_font(U"Lv.").drawAt(40, (int)mainView.w / 2 + mainView.x-210, (int)mainView.y + 300);
	m_font(m_level).drawAt(100,(int)mainView.w / 2 + mainView.x-85,(int)mainView.y + 275);
	Rect texRect{ (int)mainView.w / 2 + mainView.x + 50,(int)mainView.y + 130,150,150 };
	m_font(m_texName).drawAt(30,(int) texRect.x+texRect.w/2, (int)texRect.y + texRect.h + 25);
	texRect.draw(ColorF{ 1 });
	//texRect.drawFrame(frameThickness);
	texRect(m_tex(0,0,300,300)).draw();
	retryRect.draw(ColorF{ 1.0,m_retryTransition.value() }).drawFrame(2);
	m_font(U"Retry").drawAt(retryRect.center(), ColorF{ 1 - m_retryTransition.value() });
	titleRect.draw(ColorF{ 1.0,m_titleTransition.value() }).drawFrame(2);
	m_font(U"Title").drawAt(titleRect.center(), ColorF{ 1 - m_titleTransition.value() });
}

void resultView::update(int32 level,Texture tex, String name) {
	m_level = level;
	m_tex = tex;
	m_texName = name;
	Rect retryRect{ Arg::center((int)Scene::Width() / 2 - 150 ,460),200,70 };
	Rect titleRect{ Arg::center((int)Scene::Width() / 2 + 150 ,460),200,70 };
	const bool MouseOver = retryRect.mouseOver() || titleRect.mouseOver();
	//if (MouseOver)
	//{
	//	TextureAsset(U"finger").draw(Cursor::Pos());
	//}
	if (retryRect.leftClicked())
	{
		m_retryPressed = true;
	}
	if (titleRect.leftClicked())
	{
		m_titlePressed = true;
	}
	m_retryTransition.update(retryRect.mouseOver());
	m_titleTransition.update(titleRect.mouseOver());


	//if (m_retryRect.mouseOver())
	//{
	//	Cursor::RequestStyle(CursorStyle::Hand);
	//}
	//if (m_titleRect.mouseOver())
	//{
	//	Cursor::RequestStyle(CursorStyle::Hand);
	//}
}

bool resultView::getRetryPressed()
{
	return m_retryPressed;
}
bool resultView::getTitlePressed()
{
	return m_titlePressed;
}

#include "stdafx.h"
#include "resultView.hpp"

Rect resultView::getRetryRect() {
	return m_retryRect;
}
Rect resultView::getTitleRect() {
	return m_titleRect;
}

void resultView::draw() const{
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
	m_retryRect.draw(ColorF{ 1.0,m_retryTransition.value() }).drawFrame(2);
	m_font(U"Retry").drawAt(m_retryRect.center(), ColorF{ 1 - m_retryTransition.value() });
	m_titleRect.draw(ColorF{ 1.0,m_titleTransition.value() }).drawFrame(2);
	m_font(U"Title").drawAt(m_titleRect.center(), ColorF{ 1 - m_titleTransition.value() });
}

void resultView::update(int32 level,Texture tex) {
	m_level = level;
	m_tex = tex;
	const bool MouseOver = m_retryRect.mouseOver() || m_titleRect.mouseOver();
	if (MouseOver)
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}
	if (m_retryRect.leftClicked())
	{
		m_retryPressed = true;
	}
	if (m_titleRect.leftClicked())
	{
		m_titlePressed = true;
	}
	m_retryTransition.update(m_retryRect.mouseOver());
	m_titleTransition.update(m_titleRect.mouseOver());


	if (m_retryRect.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}
	if (m_titleRect.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}
}

bool resultView::getRetryPressed()
{
	return m_retryPressed;
}
bool resultView::getTitlePressed()
{
	return m_titlePressed;
}

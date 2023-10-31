﻿#include "stdafx.h"
#include "resultView.hpp"

Rect resultView::getRetryRect() {
	return m_retryRect;
}
Rect resultView::getTitleRect() {
	return m_titleRect;
}

void resultView::draw() {
	const int32 frameThickness = 20;
	Rect mainView{ Arg::center((int)Scene::Width() / 2,(int)Scene::Height() / 2),600,450 };
	mainView.draw(ColorF{ 0.15 });
	Rect mainViewFrame{ Arg::center((int)Scene::Width() / 2,(int)Scene::Height() / 2),620,470 };
	mainViewFrame.drawFrame(frameThickness, ColorF{ 0 });
	m_font(U"Result").drawAt(60, (int)mainView.w / 2 + mainView.x, (int)mainView.y + 40);
	Line{ (int)mainView.x+30, (int)mainView.y+100, (int)mainView.x + mainView.w-30,  (int)mainView.y + 100 }.draw(LineStyle::SquareDot, 12, Palette::White);
	m_font(U"Lv.").drawAt(40, (int)mainView.w / 2 + mainView.x-100, (int)mainView.y + 200);
	m_font(m_level).drawAt(60,(int)mainView.w / 2 + mainView.x,(int)mainView.y + 200);
}

void resultView::update(int32 level) {
	m_level = level;
}

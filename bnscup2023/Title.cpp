#include "Title.hpp"

Title::Title(const InitData& init)
	:IScene{init}{}


void Title::update()
{
	m_startTransition.update(m_startButton.mouseOver());

	if (m_startButton.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	if (m_startButton.leftClicked())
	{
		changeScene(State::Game);
	}
}

void Title::draw() const
{
	Scene::SetBackground(ColorF{ 0.2,0.8,0.4 });
	FontAsset(U"MiddleFont")(U"TITLE").drawAt(TextStyle::OutlineShadow(0.2, ColorF{ 0.2, 0.6, 0.2 },
		Vec2{ 3, 3 }, ColorF{ 0.0, 0.5 }), 100, Vec2{ 400, 100 });
	m_startButton.draw(ColorF{ 1.0,m_startTransition.value() }).drawFrame(2);

	FontAsset(U"MiddleFont")(U"Start").drawAt(m_startButton.center(), ColorF{ 0.25 });
}

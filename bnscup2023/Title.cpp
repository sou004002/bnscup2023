#include "Title.hpp"

Title::Title(const InitData& init)
	:IScene{init}{}


void Title::update()
{
	m_accumulator += Scene::DeltaTime();
	m_bubblePos.y -= (int)m_accumulator;
	if (m_bubblePos.y < 0) {
		m_bubblePos.y = (int)Scene::Height();
	}
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
	Scene::SetBackground(ColorF{ 0.494,0.796,0.902 });
	TextureAsset(U"backGround").scaled(1.2).draw(Arg::bottomLeft(0,Scene::Height()));
	FontAsset(U"MiddleFontJap")(U"Hello, Siv3D!").draw(40, 40);
	FontAsset(U"MiddleFontJap")(U"餌をやる。").draw(TextStyle::Shadow(Vec2{2,2},ColorF{0.0,0.5}), 45, Arg::leftCenter(300, 150));
	FontAsset(U"MiddleFontJap")(U"そして").draw(TextStyle::Shadow(Vec2{ 2,2 }, ColorF{ 0.0,0.5 }), 45, Arg::leftCenter(300, 210));
	FontAsset(U"MiddleFontJap")(U"ごみを拾う。").draw(TextStyle::Shadow(Vec2{ 2,2 }, ColorF{ 0.0,0.5 }), 45, Arg::leftCenter(300, 270));
	
	m_startButton.draw(ColorF{ 1.0,m_startTransition.value() }).drawFrame(2);

	FontAsset(U"MiddleFont")(U"Start").drawAt(m_startButton.center(), ColorF{ 1-m_startTransition.value() });
}

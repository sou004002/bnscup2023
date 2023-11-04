#include "Title.hpp"

Title::Title(const InitData& init)
	:IScene{init}{}


void Title::update()
{
	m_accumulator += Scene::DeltaTime();
	for (auto& p : m_bubblePos)
	{
		p.y -= Scene::DeltaTime() * 100;
		p.x+= (Periodic::Sine1_1(2s, Scene::Time()) * 0.5);
		if (p.y < 0) {
			p.y= Random((int)Scene::Height(), (int)Scene::Height() * 2);
			p.x= Random(50, (int)Scene::Width() - 50);
		}
	}

	m_startTransition.update(m_startButton.mouseOver());

	setIsHand(m_startButton.mouseOver());


	if (m_startButton.leftClicked())
	{
		changeScene(State::Game);
	}
}

void Title::draw() const
{
	Scene::SetBackground(ColorF{1});
	TextureAsset(U"backGround").scaled(0.25).draw(Arg::bottomLeft(0,Scene::Height()));
	for (auto& p : m_bubblePos)
	{
		m_bubble.scaled(0.3).draw(p);
	}
	
	FontAsset(U"MiddleFontJap")(U"餌をやる。").draw(TextStyle::Shadow(Vec2{2,2},ColorF{0.0,0.5}), 45, Arg::leftCenter(300, 150));
	FontAsset(U"MiddleFontJap")(U"そして").draw(TextStyle::Shadow(Vec2{ 2,2 }, ColorF{ 0.0,0.5 }), 45, Arg::leftCenter(300, 210));
	FontAsset(U"MiddleFontJap")(U"ごみを拾う。").draw(TextStyle::Shadow(Vec2{ 2,2 }, ColorF{ 0.0,0.5 }), 45, Arg::leftCenter(300, 270));
	m_startButton.draw(ColorF{ 1.0,m_startTransition.value() }).drawFrame(2);

	FontAsset(U"MiddleFont")(U"Start").drawAt(m_startButton.center(), ColorF{ 1-m_startTransition.value() });
	if (getIsHand())
	{
		TextureAsset(U"finger").resized(60).draw(Cursor::Pos().x - 20, Cursor::Pos().y - 5);
	}
	else
	{
		TextureAsset(U"cursor").resized(60).draw(Cursor::Pos().x - 20, Cursor::Pos().y - 13);
	}
}

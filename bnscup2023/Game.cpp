#include "Game.hpp"

Game::Game(const InitData& init)
	:IScene{ init }
{
	

}

void Game::update()//値の更新を行う。drawしても描画されない
{
	ClearPrint();
	m_accumulator += Scene::DeltaTime();
	m_foodBtn.update();
	if(m_foodBtn.getPressed())
	{
		m_cursor.m_image = m_cursor.m_otete;
		m_cursor.m_feed = true;
		m_cursor.m_pickGarbage = false;
	}
	else
	{
		m_cursor.m_image = m_cursor.m_net;
		m_cursor.m_feed = false;
		m_cursor.m_pickGarbage = true;
	}
	//if (MouseR.down())
	//{
	//	levelIcon.levelUp();
	//}
	for (auto& gab : m_garbages)
	{
		gab.changehitter(m_accumulator);
	}
	m_fish1.move();//polygonは描画されない
	if (MouseL.down() && m_foodBtn.getPressed()) {
		if (m_cursor.m_feed && m_aqua_pos.x <= Cursor::Pos().x && Cursor::Pos().x <= m_aqua_pos.x + m_aqua_w) {
			m_arrayFood.push_back(Food(Cursor::Pos().x, m_aqua_pos, m_aqua_w, m_aqua_h, m_aqua)); //ここで配列にこれを追加したい
		}
	}
	for (auto& i : m_arrayFood) {
	i.move();
		if (i.m_trashTime >= 1) {
			Garbage g(30.0, m_dust, m_accumulator, 1);
			g.putpoints(Vec2{ i.m_x, i.m_y });
			m_garbages << g;
		}
	}
	m_arrayFood.remove_if([](const Food& food) { return (food.m_trashTime >= 1); });
	m_cursor.move(m_aqua_pos.x, m_aqua_pos.x + m_aqua_w, m_aqua_pos.y + m_aqua_h);

}

void Game::draw() const //描画を行う。const関数のみ呼べる
{
	TextureAsset(U"blackBorder").scaled(0.5).draw();
	TextureAsset(U"blackBorder").scaled(0.5).draw((int32)(TextureAsset(U"blackBorder").width() / 2), -30);
	m_aqua.init();
	m_hpBar.draw(HPRect);
	FontAsset(U"MiddleFont")(U"HP").draw(30, m_HPBarPosX - 60, m_HPBarPosY);
	m_expBar.draw(m_EXPRect);

	m_levelIcon.draw();
	m_foodBtn.draw();

	for (auto& gab : m_garbages)
	{
		if (gab.gethitter()) {
			gab.draw();
		}
	}

	m_fish1.draw();
	for (auto& i : m_arrayFood) {
		i.draw();
	}

	m_cursor.draw();
}

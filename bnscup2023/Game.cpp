#include "Game.hpp"

Game::Game(const InitData& init)
	:IScene{ init }
{
	//Garbage::coolTime = 3.0;
	//Garbage::time = 0;
	/*Print << U"con";*/
}

void Game::update()//値の更新を行う。drawしても描画されない
{
	Cursor::RequestStyle(CursorStyle::Hidden);
	//リザルトフラグが経っていたら
	if (m_isResult) {
		m_resultView.update(m_levelIcon.getLevel(), m_blueFishTex);//リザルトビューの更新
		if (m_resultView.getTitlePressed()) {
			changeScene(State::Title);

		}
		if (m_resultView.getRetryPressed()) {
			changeScene(State::Game);
		}
		return;//他の挙動は行わない
	}

	ClearPrint();
	m_accumulator += Scene::DeltaTime();
	m_foodBtn.update();

	//水槽内のごみの数の初期化
	garbage_in_aq = 0;
	for (auto& gab : m_garbages)
	{
		gab.changehitter(m_accumulator);
		if (gab.gethitter())
		{//表示されてて
			garbage_in_aq = garbage_in_aq + 1;
			if (!m_foodBtn.getPressed())
			{
				if (gab.getcircle().mouseOver())
				{
					if (gab.getcircle().leftClicked())
					{
						gab.set_hit(false);
						gab.set_time(Garbage::coolTime + Garbage::time);
						Garbage::time = Garbage::coolTime + Garbage::time;
						garbage_in_aq = garbage_in_aq - 1;
					}

				}
				if (gab.get_del() == false)
				{
					garbage_in_aq = garbage_in_aq + 1;
				}
			}
		}
	}
	for (auto& gab : m_garbageFromFood)
	{
		for (auto& gab2 : m_garbageFromFood)
		{
			if (&gab!=&gab2)
			{
				if (!(gab.get_del() || gab2.get_del())) {
					if (gab.getcircle().intersects(gab2.getcircle()))
					{
						gab.set_del(true);
					}
				}
			}
		}
	}
	for (auto& gab : m_garbageFromFood)
	{
		if (!m_foodBtn.getPressed())
		{
			if (gab.getcircle().mouseOver())
			{
				if (gab.getcircle().leftClicked())
				{
					gab.set_del(true);
				}
			}
		}
	}

	if (m_levelIcon.getLevel() < 2)
		m_blueFish.move();
	else if (2 <= m_levelIcon.getLevel() and m_levelIcon.getLevel() < 3)
		m_whiteFish.move();
	else if (3 <= m_levelIcon.getLevel() and m_levelIcon.getLevel() < 4)
		m_tatsu.move();
	else if (4 <= m_levelIcon.getLevel() and m_levelIcon.getLevel() < 5)
		m_turtle.move();
	else if (5 <= m_levelIcon.getLevel())
		m_jerryFish.move();

	if (MouseL.down() && m_foodBtn.getPressed() && m_marginTime >= 1) {
		if (m_cursor.m_feed && m_aqua_pos.x <= Cursor::Pos().x && Cursor::Pos().x <= m_aqua_pos.x + m_aqua_w) {
			m_arrayFood.push_back(Food(Cursor::Pos().x, m_aqua_pos, m_aqua_w, m_aqua_h, m_aqua)); //ここで配列にこれを追加したい
		}
		m_marginTime = 0.0;
	}
	m_marginTime += Scene::DeltaTime();
	if (m_foodBtn.getPressed())
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
	for (auto& i : m_arrayFood) {
		i.move();
		if (i.m_trashTime >= 1) {
			if (m_garbages.size() <= max_garbage_number)
			{
				Garbage g(70.0, m_dust, m_accumulator, 1);
				g.putpoints(Vec2{ i.m_x, i.m_y-10 });
				g.set_hit(true);
				m_garbageFromFood << g;
				garbage_in_aq = garbage_in_aq + 1;
			}
		}
		if (!i.m_eaten) {
			if ((m_levelIcon.getLevel() < 2 and m_blueFish.isCollision(i.m_esaesa))
				or (2 <= m_levelIcon.getLevel() and m_levelIcon.getLevel() < 3
					and m_whiteFish.isCollision(i.m_esaesa))
				or (3 <= m_levelIcon.getLevel() and m_levelIcon.getLevel() < 4
					and m_tatsu.isCollision(i.m_esaesa))
				or (4 <= m_levelIcon.getLevel() and m_levelIcon.getLevel() < 5
					and m_turtle.isCollision(i.m_esaesa))
				or (5 <= m_levelIcon.getLevel() and m_jerryFish.isCollision(i.m_esaesa)))
			{//&&fish1の満腹度が最大ではない
					i.m_eaten = true;
					//経験値を増加させる。
					m_EXP += 10;
			}
		}
		else { i.m_eaten = false; }//冗長に思えるかもしれないけど必要です。
	}
	if (m_EXP >=m_expBar.getMaxHP())
	{
		m_EXP = 0;
		m_levelIcon.levelUp();
		m_expBar.setMaxHP((m_levelIcon.getLevel())*m_maxEXP*0.5);
		//Print << (m_levelIcon.getLevel() * 0.8) * m_maxEXP;

		if (m_levelIcon.getLevel() == 2)
		{
			m_whiteFish.move(m_blueFish.getPoint());
			effect.add<RingEffect>(Vec2{ m_blueFish.getPoint().x + 50, m_blueFish.getPoint().y + 20 });
		}
		else if (m_levelIcon.getLevel() == 3)
		{
			m_tatsu.move(m_whiteFish.getPoint());
			effect.add<RingEffect>(Vec2{ m_whiteFish.getPoint().x + 50, m_whiteFish.getPoint().y + 20 });
		}
		else if (m_levelIcon.getLevel() == 4)
		{
			m_turtle.move(m_tatsu.getPoint());
			effect.add<RingEffect>(Vec2{ m_tatsu.getPoint().x + 50, m_tatsu.getPoint().y + 20 });
		}
		else if (m_levelIcon.getLevel() == 5)
		{
			m_jerryFish.move(m_turtle.getPoint());
			effect.add<RingEffect>(Vec2{ m_turtle.getPoint().x + 50, m_turtle.getPoint().y + 20 });
		}
	}
	m_expBar.setHP(m_EXP);
	
	m_arrayFood.remove_if([](const Food& food) { return (food.m_eaten); });
	m_arrayFood.remove_if([](const Food& food) { return (food.m_trashTime >= 1); });
	m_cursor.move(m_aqua_pos.x, m_aqua_pos.x + m_aqua_w, m_aqua_pos.y + m_aqua_h);
	m_garbages.remove_if([](const Garbage& garbage) { return (garbage.get_del()); });
	m_garbageFromFood.remove_if([](const Garbage& garbage) { return (garbage.get_del()); });

	//ごみの数によってダメージ
	m_hpBar.damage(garbage_in_aq);

	m_resultView.update(m_levelIcon.getLevel(), m_blueFishTex);

	if (m_hpBar.getHP() <= 0) {
		m_isResult = true;
	}
	
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
			gab.draw(gab.getcircle().mouseOver() && !m_foodBtn.getPressed());
		}
	/*		Print << gab.get_time();*/
	}
	for (auto& gab : m_garbageFromFood)
	{
		if (gab.gethitter()) {
			gab.draw(gab.getcircle().mouseOver() && !m_foodBtn.getPressed());
		}
	}

	if (m_levelIcon.getLevel() < 2)
		m_blueFish.draw();
	else if (2 <= m_levelIcon.getLevel() and m_levelIcon.getLevel() < 3)
		m_whiteFish.draw();
	else if (3 <= m_levelIcon.getLevel() and m_levelIcon.getLevel() < 4)
		m_tatsu.draw();
	else if (4 <= m_levelIcon.getLevel() and m_levelIcon.getLevel() < 5)
		m_turtle.draw();
	else if (5 <= m_levelIcon.getLevel())
		m_jerryFish.draw();

	for (auto& i : m_arrayFood) {
		i.draw();
	}

	if (m_foodBtn.getRect().mouseOver())
	{
		TextureAsset(U"finger").resized(60).draw(Cursor::Pos().x - 20, Cursor::Pos().y - 5);
	}
	else {
		m_cursor.draw();
	}
	if (m_isResult) {
		m_resultView.draw();
		if (m_resultView.getRetryRect().mouseOver() || m_resultView.getTitleRect().mouseOver())
		{
			TextureAsset(U"finger").resized(60).draw(Cursor::Pos().x-20,Cursor::Pos().y-5);
		}
		else
		{
			TextureAsset(U"cursor").resized(60).draw(Cursor::Pos().x - 20, Cursor::Pos().y - 13);
		}
	}
	// エフェクトを追加する
	//effect.add<RingEffect>(Cursor::Pos());

	//エフェクトの更新
	effect.update();
}

//void Game::retry()
//{
//	m_level = m_initialLevel;
//	m_charaName = U"blueFish";
//	m_isResult = false;
//	changeScene(State::Game);
//
//	m_accumulator = 0;
//}

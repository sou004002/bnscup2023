#include "Game.hpp"

Game::Game(const InitData& init)
	:IScene{ init }
{


}

void Game::update()//値の更新を行う。drawしても描画されない
{
	//リザルトフラグが経っていたら
	if (m_isResult) {
		m_resultView.update(m_level, m_blueFishTex);//リザルトビューの更新
		if (m_resultView.getTitlePressed()) {
			changeScene(State::Title);
		}
		if (m_resultView.getRetryPressed()) {
			retry();
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
		if (gab.gethitter()) {//表示されてて
			if (!m_foodBtn.getPressed()) {
				if (gab.getcircle().mouseOver())
				{
					if (gab.getcircle().leftClicked())
					{
						gab.set_hit(false);
						gab.set_time(Garbage::coolTime + Garbage::time);
						Garbage::time = Garbage::coolTime + Garbage::time;
					}

				}
				if (gab.get_del() == false)
				{
					garbage_in_aq = garbage_in_aq + 1;
				}
			}
		}
		
	}
	m_fish1.move();
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
				m_garbages << g;
				garbage_in_aq = garbage_in_aq + 1;
			}
		}
		if (!i.m_eaten) {
			if (m_fish1.isCollision(i.m_esaesa)) {//&&fish1の満腹度が最大ではない
				i.m_eaten = true;
				Print << U"umai";
				//経験値を増加させる。
			}
		}
		else { i.m_eaten = false; }//冗長に思えるかもしれないけど必要です。
	}
	
	m_arrayFood.remove_if([](const Food& food) { return (food.m_eaten); });
	m_arrayFood.remove_if([](const Food& food) { return (food.m_trashTime >= 1); });
	m_cursor.move(m_aqua_pos.x, m_aqua_pos.x + m_aqua_w, m_aqua_pos.y + m_aqua_h);
	m_garbages.remove_if([](const Garbage& garbage) { return (garbage.get_del()); });

	//ごみの数によってダメージ
	damage = guard - garbage_in_aq;
	if (damage > 0) damage = 0;
	m_hpBar.damage(abs(damage));

	//全てのごみがなくなったら新たに生成する
	//if (m_garbages.size() == 0)
	//{
	//	m_garbages = Garbage::GenerateRandomPoints(m_SceneRect, 50.0, 70.0, m_dust,m_accumulator,Garbage::coolTime);
	//}

	m_resultView.update(m_level, m_blueFishTex);

	if (MouseR.down()) {
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

	m_cursor.draw();
	for (auto& gab : m_garbages)
	{
		if (gab.gethitter()) {
			gab.draw(gab.getcircle().mouseOver());
			Print << gab.get_time();
		}
	}

	m_fish1.draw();
	for (auto& i : m_arrayFood) {
		i.draw();
	}

	m_cursor.draw();
	if (m_isResult) {
		m_resultView.draw();
	}
}

void Game::retry()
{
	m_level = m_initialLevel;
	m_charaName = U"blueFish";
	m_isResult = false;
	changeScene(State::Game);
}

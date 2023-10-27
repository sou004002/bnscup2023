#include <Siv3D.hpp>
#include "Fish.hpp"
#include "Garbage.hpp"
#include "Mousecursor.h"
#include "Food.h"
#include "Aquarium.hpp"



void Main()
{
	const Texture texture{ U"dotImages/whiteFish.svg" };
	Fish fish(200, 300, 100, texture, 2);

	//水槽の作成
	const Texture backGround{ U"dotImages/bg.svg" };
	const int32 aqua_frameThick = 5;
	const int32 aqua_w = Scene::Width() - aqua_frameThick * 2;
	const int32 aqua_h = 400;
	const Vec2 aqua_pos = { Scene::Width() - (aqua_w + aqua_frameThick),
		Scene::Height() - (aqua_h + aqua_frameThick) };//左上の座標
	Aquarium gv(backGround, aqua_pos, aqua_w, aqua_h, aqua_frameThick);

	constexpr Rect SceneRect{ 0, 0, 800, 600 };
	const Texture gomi{ U"dotImages/garbage.svg" };
	double accumulator = 0.0;

	Array<Garbage> garbages = Garbage::GenerateRandomPoints(SceneRect, 52.0, 30, gomi);

	Mousecursor cursor(200, 300);
	std::vector<Food> arrayFood; //Foodの配列を用意して、generateのたびに追加

	while (System::Update())
	{
		ClearPrint();
		gv.init();

		if (SimpleGUI::Button(U"エサを与える", Vec2{ 30, 400 })) {
			cursor.m_image = cursor.m_otete;
			cursor.m_feed = true;
			cursor.m_pickGarbage = false;
		}
		if (SimpleGUI::Button(U"ゴミを片付ける", Vec2{ 30, 450 })) {
			cursor.m_image = cursor.m_net;
			cursor.m_feed = false;
			cursor.m_pickGarbage = true;
		}

		accumulator += Scene::DeltaTime();
		for (auto& gab : garbages)
		{
			gab.changehitter(accumulator);
			if (gab.gethitter() == true)
			{
				gab.changepos();
				gab.draw();
			}
		}

		fish.move();
		fish.draw();

		if (MouseL.down()) {
			if (cursor.m_feed && aqua_pos.x <= Cursor::Pos().x && Cursor::Pos().x <= aqua_pos.x+aqua_w) {
				arrayFood.push_back(Food(Cursor::Pos().x, aqua_pos, aqua_w, aqua_h)); //ここで配列にこれを追加したい
			}
		}
		for (Food& i : arrayFood) {//全ての餌を処理する。
			i.move();
			i.draw();
			i.removal();
			if (i.m_trashTime >= 100) {
				//ゴミに変換
				//x座標は何らかの方法で保持
				//Garbage gm(s, t, z);//これを配列に加える。
			}
		}
		cursor.move(aqua_pos.x, aqua_pos.x+aqua_w, aqua_pos.y+aqua_h);
		cursor.draw();
	}
}

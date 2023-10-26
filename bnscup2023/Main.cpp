#include <Siv3D.hpp>
#include "Fish.hpp"
#include "Garbage.hpp"
#include "Mousecursor.h"
#include "Food.h"



void Main()
{
	const Texture emoji{ U"🐟"_emoji };
	const Texture texture{ U"dotImages\\peixinhos1.png" };
	Fish fish(200, 300, 70, texture);

	constexpr Rect SceneRect{ 0, 0, 800, 600 };
	const Texture gomi{ U"🗑"_emoji };
	double accumulator = 0.0;

	Array<Garbage> garbages = Garbage::GenerateRandomPoints(SceneRect, 52.0, 30, gomi);
	
	Mousecursor cursor(200, 300);
	std::vector<Food> arrayFood; //Foodの配列を用意して、generateのたびに追加

	constexpr Rect SceneRect{ 0, 0, 800, 600 };
	const Texture gomi{ U"🗑"_emoji };
	double accumulator = 0.0;

	Array<Garbage> garbages = Garbage::GenerateRandomPoints(SceneRect, 52.0, 30, gomi);

	while (System::Update())
	{
		ClearPrint();
		Line{ 300, 200, 300, 600 }.draw(3, Palette::White);
		Line{ 700, 200, 700, 600 }.draw(3, Palette::White);
		Line{ 300, 600, 700, 600 }.draw(3, Palette::White);
		if (SimpleGUI::Button(U"エサを与える", Vec2{ 30, 400 })) {
			cursor.texture = cursor.otete;
			cursor.feed = true;
			cursor.pickGarbage = false;
		}
		if (SimpleGUI::Button(U"ゴミを片付ける", Vec2{ 30, 450 })) {
			cursor.texture = cursor.net;
			cursor.feed = false;
			cursor.pickGarbage = true;
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
			if (cursor.feed && 300 <= Cursor::Pos().x && Cursor::Pos().x <= 700) {
				arrayFood.push_back(cursor.generate(Cursor::Pos().x)); //ここで配列にこれを追加したい
			}
		}
		for (Food& i : arrayFood) {//全ての餌を処理する。
			i.move();
			i.draw();
			if (i.trash_time >= 100) {
				//ゴミに変換
				//x座標は何らかの方法で保持
				//Garbage gm(s, t, z);//これを配列に加える。
			}
		}
		cursor.move();
		cursor.draw();
		}



	}
}

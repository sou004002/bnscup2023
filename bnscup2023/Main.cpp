#include <Siv3D.hpp>
#include "Fish.hpp"
#include "Garbage.hpp"
#include "Mousecursor.h"
#include "Food.h"
#include "Aquarium.hpp"



void Main()
{

	//水槽の作成
	const Texture backGround{ U"dotImages/bg.svg" };
	const int32 aqua_frameThick = 5;
	const int32 aqua_w = Scene::Width() - aqua_frameThick * 2;
	const int32 aqua_h = 400;
	const Vec2 aqua_pos = { Scene::Width() - (aqua_w + aqua_frameThick),
		Scene::Height() - (aqua_h + aqua_frameThick) };//右下詰め
	Aquarium gv(backGround, aqua_pos, aqua_w, aqua_h, aqua_frameThick);

	const Texture emoji{ U"🐟"_emoji };
	const Image image{ U"dotImages/whiteFish.svg" };
	const Texture fBtn{ U"🍴"_emoji };
	Fish fish1(200, 300, 100.0, image, 2, gv);
	Fish fish2(200, 300, 300.0, image, 2, gv);

	constexpr Rect SceneRect{ 0, 0, 800, 600 };
	const Texture gomi{ U"🗑"_emoji };
	double accumulator = 0.0;

	Array<Garbage> garbages = Garbage::GenerateRandomPoints(SceneRect, 52.0, 30, gomi);

	Mousecursor cursor(200, 300);
	std::vector<Food> arrayFood; //Foodの配列を用意して、generateのたびに追加

	while (System::Update())
	{
		ClearPrint();
		gv.init();

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

		fish1.move();
		fish2.move();
		fish1.draw();
		fish2.draw();

		String st;
		if (fish1.isCollision(fish2))
		{
			st = U"こりじょん！！";
		}
		else
		{
			st = U"のっとこりじょん！！";
		}
		Print << st;

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

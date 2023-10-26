# include "Mousecursor.h"
#include "Food.h"
#include <Siv3D.hpp>
void Main()
{
	Mousecursor cursor(200, 300);
	std::vector<Food> arrayFood; //Foodの配列を用意して、generateのたびに追加
	while (System::Update())
	{
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
		ClearPrint();
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


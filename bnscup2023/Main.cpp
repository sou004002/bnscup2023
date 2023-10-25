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
			cursor.esa = true;
			cursor.gomi = false;
		}
		if (SimpleGUI::Button(U"ゴミを片付ける", Vec2{ 30, 450 })) {
			cursor.texture = cursor.ami;
			cursor.esa = false;
			cursor.gomi = true;
		}
		ClearPrint();
		if (MouseL.down()) {
			if (cursor.esa && 300 <= Cursor::Pos().x && Cursor::Pos().x <= 700) {
				arrayFood.push_back(cursor.generate(Cursor::Pos().x)); //ここで配列にこれを追加したい
			}
		}
		for (Food& i : arrayFood) {//全ての餌を処理する。
			i.move();
			i.draw();
		}
		cursor.move();
		cursor.draw();
	}
}


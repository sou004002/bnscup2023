﻿#include <Siv3D.hpp>
#include "Fish.hpp"
#include "Garbage.hpp"
#include "Mousecursor.h"
#include "Food.h"
#include "Aquarium.hpp"
#include "HPBar.hpp"
#include "LvIcon.hpp"
#include "FoodBtn.hpp"
#include "resultView.hpp"

void Main()
{
	TextureAsset::Register(U"blackBorder", U"dotImages/blackBorder.svg");

	//水槽の作成
	const Texture backGround{ U"dotImages/bg.svg" };
	const int32 aqua_frameThick = 5;
	const int32 aqua_w = Scene::Width() - aqua_frameThick * 2;
	const int32 aqua_h = 400;
	const Vec2 aqua_pos = { Scene::Width() - (aqua_w + aqua_frameThick),
		Scene::Height() - (aqua_h + aqua_frameThick) };//左上の座標
	Aquarium gv(backGround, aqua_pos, aqua_w, aqua_h, aqua_frameThick);
	//HPバー
	const ColorF HPColor{ 0.8,0.2,0.2 };
	const int32 initialHP = 400;
	const int32 HPBarPosX = 200;
	const int32 HPBarPosY = 30;
	const int32 HPBarWidth = 470;
	const int32 HPBarHeight = 30;
	HPBar hpBar{ HPColor,initialHP };
	constexpr Rect HPRect{ HPBarPosX,HPBarPosY,HPBarWidth,HPBarHeight };
	Font font{ FontMethod::MSDF, 30 ,U"example/font/INVASION2000.TTF", FontStyle::Bitmap };



	//レベルアイコン
	const Vec2 levelIconPos{ 10,10 };
	const double levelIconSize = 0.3;
	const int32 initialLevel = 1;
	LvIcon levelIcon{ levelIconPos,levelIconSize,initialLevel };


	//EXPバー
	const ColorF EXPColor{ 0, 0.851, 0.063 };
	const int32 initialEXP = 0;
	HPBar expBar{ EXPColor,initialEXP };
	const int32 EXPBarPosX = 100;
	const int32 EXPBarPosY = 30 + HPBarPosY + HPBarHeight;
	const int32 EXPBarWidth = 470 + (HPBarPosX - EXPBarPosX);
	const int32 EXPBarHeight = 15;
	constexpr Rect EXPRect{ EXPBarPosX,EXPBarPosY,EXPBarWidth,EXPBarHeight };

	FoodBtn foodBtn{ EXPBarPosX + EXPBarWidth + 20,HPBarPosY - 10,0.25 };

	//ごみの生成範囲
	const int32 g_range_w = 800;
	const int32 g_range_h = 600;
	constexpr Rect SceneRect{ 0, 0, g_range_w, g_range_h };

	const Texture emoji{ U"🐟"_emoji };
	const Image image{ U"dotImages/blueFish.svg" };
	const Texture fBtn{ U"🍴"_emoji };
	Fish fish1(200, 300, 100.0, image, 2, gv);
	//resultView rV{ levelIcon.getLevel() ,fish1.getTexture()};

	const Texture gomi{ U"🗑"_emoji };
	const Texture garb{ U"dotImages/garbageWithFrame.svg" };
	double accumulator = 0.0;

	Array<Garbage> garbages = Garbage::GenerateRandomPoints(SceneRect, 52.0, 30, garb);

	Mousecursor cursor(200, 300, gv);
	std::vector<Food> arrayFood; //Foodの配列を用意して、generateのたびに追加

	while (System::Update())
	{
		ClearPrint();
		TextureAsset(U"blackBorder").scaled(0.5).draw();
		TextureAsset(U"blackBorder").scaled(0.5).draw((int32)(TextureAsset(U"blackBorder").width() / 2), -30);
		gv.init();
		hpBar.draw(HPRect);
		font(U"HP").draw(30, HPBarPosX - 60, HPBarPosY);
		expBar.draw(EXPRect);
		//rV.draw();
		levelIcon.draw();
		foodBtn.update();
		foodBtn.draw();

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
		//rV.update(levelIcon.getLevel());
		if (MouseR.down())
		{
			levelIcon.levelUp();
		}

		accumulator += Scene::DeltaTime();
		for (auto& gab : garbages)
		{
			gab.changehitter(accumulator);
			if (gab.gethitter() == true)
			{
				gab.draw();
			}
		}

		fish1.move();
		fish1.draw();

		if (MouseL.down()) {
			if (cursor.m_feed && aqua_pos.x <= Cursor::Pos().x && Cursor::Pos().x <= aqua_pos.x + aqua_w) {
				arrayFood.push_back(Food(Cursor::Pos().x, aqua_pos, aqua_w, aqua_h)); //ここで配列にこれを追加したい
			}
		}
		for (Food& i : arrayFood) {//全ての餌を処理する。
			i.move();
			i.draw();
			i.removal();
			if (i.m_trashTime >= 10) {
				for (int32 i = 0; i < size(arrayFood); i++) {//全ての餌を処理する。
					arrayFood[i].move();
					arrayFood[i].draw();
					if (arrayFood[i].m_trashTime >= 10) {//地面に落ちてからゴミと化すまでの時間
						//garbages.push_back(Garbage(1, gomi, 0.0));
						//garbages[-1].putpoints(Vec2{ arrayFood[i].m_x, arrayFood[i].m_y });
						//要素どうやって消すの
					}
				}
			}
		}
		cursor.move(aqua_pos.x, aqua_pos.x + aqua_w, aqua_pos.y + aqua_h);
		cursor.draw();
	}
}

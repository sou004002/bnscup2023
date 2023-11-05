#include <Siv3D.hpp>

#include "Common.hpp"
#include "Title.hpp"
#include"Game.hpp"

void Main()
{
	TextureAsset::Register(U"blackBorder", U"dotImages/blackBorder.svg");
	TextureAsset::Register(U"backGround", U"dotImages/backGround_AI-s_16_0.svg");
	TextureAsset::Register(U"bubble", U"dotImages/bubble.svg");

	TextureAsset::Register(U"blueFish", U"dotImages/blueFish.svg");
	TextureAsset::Register(U"whiteFish", U"dotImages/whiteFish.svg");
	TextureAsset::Register(U"tatsu", U"dotImages/tatsu.svg");
	TextureAsset::Register(U"turtle", U"dotImages/turtle.svg");
	TextureAsset::Register(U"jerryFish", U"dotImages/jerryFish.svg");

	TextureAsset::Register(U"food", U"dotImages/food.svg");
	TextureAsset::Register(U"foodFinger", U"dotImages/foodFinger.svg");
	TextureAsset::Register(U"ami", U"dotImages/ami.svg");
	TextureAsset::Register(U"cursor", U"dotImages/cursor.svg");
	TextureAsset::Register(U"finger", U"dotImages/finger.svg");
	TextureAsset::Register(U"bg", U"dotImages/bg.svg");
	FontAsset::Register(U"MiddleFont", FontMethod::MSDF, 30, U"example/font/INVASION2000.TTF", FontStyle::Bitmap);
	FontAsset::Register(U"MiddleFontJap", FontMethod::MSDF, 30, U"example/font/misaki_gothic_2nd.ttf", FontStyle::Bitmap);
	const Font font{ 50 };
	App manager;
	manager.add<Title>(State::Title);
	manager.add<Game>(State::Game);
	//manager.init(State::Game);//ゲームシーンから始めたいときはこの行を有効にする

	

	while (System::Update())
	{
		Cursor::RequestStyle(CursorStyle::Hidden);
		Cursor::ClipToWindow(true);

		if (not manager.update())
		{
			break;
		}
		
	}
}

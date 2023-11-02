#include <Siv3D.hpp>

#include "Common.hpp"
#include "Title.hpp"
#include"Game.hpp"

void Main()
{
	TextureAsset::Register(U"blackBorder", U"dotImages/blackBorder.svg");
	TextureAsset::Register(U"backGround", U"dotImages/backGround_AI-s_16_0.svg");
	TextureAsset::Register(U"bubble", U"dotImages/bubble.svg");
	FontAsset::Register(U"MiddleFont", FontMethod::MSDF, 30, U"example/font/INVASION2000.TTF", FontStyle::Bitmap);
	FontAsset::Register(U"MiddleFontJap", FontMethod::MSDF, 30, U"example/font/misaki_gothic_2nd.ttf", FontStyle::Bitmap);
	const Font font{ 50 };
	App manager;
	manager.add<Title>(State::Title);
	manager.add<Game>(State::Game);
	manager.init(State::Game);//ゲームシーンから始めたいときはこの行を有効にする

	

	while (System::Update())
	{
		if (not manager.update())
		{
			break;
		}
		
	}
}

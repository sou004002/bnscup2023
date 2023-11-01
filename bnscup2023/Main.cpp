#include <Siv3D.hpp>

#include "Common.hpp"
#include "Title.hpp"
#include"Game.hpp"

void Main()
{
	TextureAsset::Register(U"blackBorder", U"dotImages/blackBorder.svg");
	TextureAsset::Register(U"backGround", U"dotImages/bg.svg");
	FontAsset::Register(U"MiddleFont", FontMethod::MSDF, 30, U"example/font/INVASION2000.TTF", FontStyle::Bitmap);
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

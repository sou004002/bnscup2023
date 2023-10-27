#include <Siv3D.hpp>
#include "Fish.hpp"
#include "Garbage.hpp"
#include "Aquarium.hpp"

void Main()
{
	const Texture emoji{ U"🐟"_emoji };
	const Texture texture{ U"dotImages/whiteFish.svg" };
	const Texture fBtn{ U"🍴"_emoji };
	Fish fish(200, 300, 100, texture,2);

	//水槽の作成
	const Texture backGround{ U"dotImages/bg.svg" };
	const int32 aqua_frameThick = 5;
	const int32 aqua_w = Scene::Width()-aqua_frameThick*2;
	const int32 aqua_h = 400;
	const Vec2 aqua_pos = { Scene::Width()-(aqua_w+aqua_frameThick),Scene::Height() - (aqua_h + aqua_frameThick)};//右下詰め
	Aquarium gv(backGround,aqua_pos,aqua_w,aqua_h,aqua_frameThick);

	constexpr Rect SceneRect{ 0, 0, 800, 600 };
	const Texture gomi{ U"🗑"_emoji };
	double accumulator = 0.0;
	Array<Garbage> garbages = Garbage::GenerateRandomPoints(SceneRect, 52.0, 30, gomi);

	while (System::Update())
	{

		ClearPrint();
		gv.init();
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
	}
}

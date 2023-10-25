#include <Siv3D.hpp>
#include "Fish.hpp"
#include "Garbage.hpp"



void Main()
{
	const Texture emoji{ U"🐟"_emoji };
	const Texture texture{ U"dotImages\\peixinhos1.png" };
	Fish fish(200, 300, 70, texture);

	constexpr Rect SceneRect{ 0, 0, 800, 600 };
	const Texture gomi{ U"🗑"_emoji };
	double accumulator = 0.0;

	Array<Garbage> garbages = Garbage::GenerateRandomPoints(SceneRect, 52.0, 30, gomi);

	constexpr Rect SceneRect{ 0, 0, 800, 600 };
	const Texture gomi{ U"🗑"_emoji };
	double accumulator = 0.0;

	Array<Garbage> garbages = Garbage::GenerateRandomPoints(SceneRect, 52.0, 30, gomi);

	while (System::Update())
	{
		ClearPrint();

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
	}
}

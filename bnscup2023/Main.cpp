#include <Siv3D.hpp>
#include "Fish.hpp"
#include "Garbage.hpp"

Array<Garbage> GenerateRandomPoints(const Rect& rect, double radius, int32 size, Texture tex, bool clip = false)
{
	Array<Garbage> garbage;
	PoissonDisk2D pd{ rect.size, radius };
	double time = 0.0;

	for (const auto& point : pd.getPoints())
	{
		Vec2 pos = (point + rect.pos);
		Garbage gab(size, tex, time);
		if (clip && (not rect.contains(pos)))
		{
			continue;
		}
		gab.putpoints(pos);
		garbage << gab;
		time = time + 3.0;
	}

	return garbage;
}



void Main()
{

	const Texture emoji{ U"🐟"_emoji };
	Fish fish(200, 300, 50, emoji);

	constexpr Rect SceneRect{ 0, 0, 800, 600 };
	const Texture gomi{ U"🗑"_emoji };
	double accumulator = 0.0;

	Array<Garbage> garbages = GenerateRandomPoints(SceneRect, 52.0, 30, gomi);

	while (System::Update())
	{
		ClearPrint();

		Rect field{ 0,500,800,100 };

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

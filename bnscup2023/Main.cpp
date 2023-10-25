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
	Vec2 pos = { Scene::Center().x,200 };
	float g = 9.81f;
	float t = 0.0f;
	bool isJump = false;

	const Texture emoji{ U"🐟"_emoji };
	Fish fish(200, 300, 50, emoji);

	constexpr Rect SceneRect{ 0, 0, 800, 600 };
	const Texture gomi{ U"🗑"_emoji };
	double accumulator = 0.0;

	Array<Garbage> garbages = GenerateRandomPoints(SceneRect, 52.0, 30, gomi);

	while (System::Update())
	{
		ClearPrint();
		const double delta = (Scene::DeltaTime() * 200);
		if (!isJump) {
			t += Scene::DeltaTime();
		}

		Rect field{ 0,500,800,100 };
		Circle player{ pos, 20 };


		// 上下左右キーで移動
		if (KeyLeft.pressed())
		{
			pos.x -= delta;
		}

		if (KeyRight.pressed())
		{
			pos.x += delta;
		}

		// [C] キーが押されたら中央に戻る
		if (KeyC.down())
		{
			pos = Scene::Center();
		}
		float vy = (float)t * g;
		if (player.intersects(field)) {
			t = 0.0f;
			vy = 0.0f;
			isJump = true;
		}
		if (KeySpace.pressed() && isJump) {
			vy -= 100.0f;
			isJump = false;
		}


		pos.y += vy;

		fish.move();

		field.draw();
		player.draw(Palette::Skyblue);
		fish.draw();
		Print << vy;

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
	}
}

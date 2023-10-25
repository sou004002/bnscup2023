#include <Siv3D.hpp>
#include "Fish.hpp"

void Main()
{

	const Texture emoji{ U"🐟"_emoji };
	Fish fish(200, 300, 50, emoji);

	while (System::Update())
	{
		ClearPrint();
		const double delta = (Scene::DeltaTime() * 200);

		Rect field{ 0,500,800,100 };

		fish.move();

		fish.draw();


	}
}

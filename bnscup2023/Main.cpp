#include <Siv3D.hpp>
#include "Fish.hpp"

void Main()
{

	const Texture emoji{ U"🐟"_emoji };
	const Texture texture{ U"pixel ocean\\peixinhos1.png" };
	Fish fish(200, 300, 70, texture);

	while (System::Update())
	{
		ClearPrint();
		const double delta = (Scene::DeltaTime() * 200);

		Rect field{ 0,500,800,100 };

		fish.move();
		fish.draw();
	}
}

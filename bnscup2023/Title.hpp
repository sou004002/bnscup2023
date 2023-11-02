#pragma once
#include "Common.hpp"

class Title :public App::Scene
{
public:

	Title(const InitData& init);

	void update() override;

	void draw() const override;

private:

	Rect m_startButton{ Arg::center(Scene::Center().x,500),300,60 };
	Transition m_startTransition{ 0.4s,0.2s };
	Texture m_bubble = TextureAsset(U"bubble");
	Array<Vec2> m_bubblePos = { {Random(50, (int)Scene::Width()-50),Random((int)Scene::Height(),(int)Scene::Height()*2)}
	,{Random(50, (int)Scene::Width() - 50),Random((int)Scene::Height(),(int)Scene::Height() * 2)}
	,{Random(50, (int)Scene::Width() - 50),Random((int)Scene::Height(),(int)Scene::Height() * 2)} }; //Foodの配列を用意して、generateのたびに追加
	double m_accumulator = 0.0;
};

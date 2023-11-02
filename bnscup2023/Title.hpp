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
	Vec2 m_bubblePos{ 0,(int)Scene::Height()};
	double m_accumulator = 0.0;
};

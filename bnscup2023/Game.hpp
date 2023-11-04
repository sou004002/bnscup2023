#pragma once
#include "Common.hpp"
#include "Aquarium.hpp"
#include "HPBar.hpp"
#include "LvIcon.hpp"
#include "FoodBtn.hpp"
#include "Garbage.hpp"
#include "Fish.hpp"
#include "resultView.hpp"
#include "Mousecursor.h"
class Game : public App::Scene
{
public:

	Game(const InitData& init);
	void update() override;
	void draw() const override;
	void retry();

private:
	const Texture m_backGround = Texture(U"dotImages/bg.svg");
	const int32 m_aqua_frameThick = 5;
	const int32 m_aqua_w = Scene::Width() - m_aqua_frameThick * 2;
	const int32 m_aqua_h = 400;
	const Vec2 m_aqua_pos = { Scene::Width() - (m_aqua_w + m_aqua_frameThick),
		Scene::Height() - (m_aqua_h + m_aqua_frameThick) };//左上の座標
	const Aquarium m_aqua{ m_backGround,m_aqua_pos,m_aqua_w,m_aqua_h,m_aqua_frameThick};

	const ColorF m_HPColor{ 0.8,0.2,0.2 };
	const int32 m_initialHP = 30000;
	const int32 m_HPBarPosX = 200;
	const int32 m_HPBarPosY = 30;
	const int32 m_HPBarWidth = 470;
	const int32 m_HPBarHeight = 30;
	HPBar m_hpBar{ m_HPColor,m_initialHP };
	const Rect HPRect{ m_HPBarPosX,m_HPBarPosY,m_HPBarWidth,m_HPBarHeight };

	const Vec2 m_levelIconPos{ 10,10 };
	const double m_levelIconSize = 0.3;
	const int32 m_initialLevel = 1;
	int32 m_level = m_initialLevel;
	String m_charaName = U"blueFish";
	LvIcon m_levelIcon{ m_levelIconPos,m_levelIconSize,m_level };

	const ColorF m_EXPColor{ 0, 0.851, 0.063 };
	const int32 m_initialEXP = 0;
	const int32 m_maxEXP = 30;
	int32 m_EXP = m_initialEXP;
	HPBar m_expBar{ m_EXPColor,m_maxEXP };
	const int32 m_EXPBarPosX = 100;
	const int32 m_EXPBarPosY = 30 + m_HPBarPosY + m_HPBarHeight;
	const int32 m_EXPBarWidth = 470 + (m_HPBarPosX - m_EXPBarPosX);
	const int32 m_EXPBarHeight = 15;
	const Rect m_EXPRect{ m_EXPBarPosX,m_EXPBarPosY,m_EXPBarWidth,m_EXPBarHeight };

	FoodBtn m_foodBtn{ m_EXPBarPosX + m_EXPBarWidth + 20,m_HPBarPosY - 10,0.25 };

	const int32 m_g_space = 30;
	const int32 m_g_pos_x = m_aqua.p_getter_x() + m_g_space;
	const int32 m_g_pos_y = m_aqua.p_getter_y() + m_g_space;
	const int32 m_g_range_w = m_aqua.w_getter() - m_g_space * 2;
	const int32 m_g_range_h = m_aqua.h_getter() - m_g_space * 2;
	Rect m_SceneRect{ m_g_pos_x, m_g_pos_y, m_g_range_w, m_g_range_h };

	const Texture m_dust{ U"dotImages/garbageWithFrame.svg" };
	double m_accumulator = 0.0;
	Array<Garbage> m_garbages = Garbage::GenerateRandomPoints(m_SceneRect, 50.0, 70.0, m_dust,0,Garbage::coolTime);
	Array<Garbage> m_garbageFromFood;
	int32 max_garbage_number = 100;
	int32 garbage_in_aq = 0;

	const Image m_blueFishImage{ U"dotImages/blueFish.svg" };
	const Image m_whiteFishImage{ U"dotImages/whiteFish.svg" };
	const Image m_tatsuImage{ U"dotImages/tatsu.svg" };
	const Image m_turtleImage{ U"dotImages/turtle.svg" };
	const Image m_jerryFishImage{ U"dotImages/jerryFish.svg" };
	Fish m_fish{ 200, 300, 100.0, TextureAsset(U"blueFish"), 2, m_aqua};

	//マウスカーソル
	const Image m_otete{ U"dotImages/foodFinger.svg" };
	const Image m_ami{ U"dotImages/ami.svg" };
	const Image m_allow{ U"dotImages/cursor.svg" };
	Mousecursor m_cursor{ 200.0, 300.0, TextureAsset(U"foodFinger"),
		TextureAsset(U"ami"), TextureAsset(U"cursor"), m_aqua };
	Array<Food> m_arrayFood; //Foodの配列を用意して、generateのたびに追加
	double m_marginTime = 3.0;

	const Texture m_blueFishTex = TextureAsset(U"blueFish");
	resultView m_resultView{ m_level,m_blueFishTex,m_charaName };
	bool m_isResult = false;

	//effect
	struct RingEffect : IEffect
	{
		Vec2 m_pos;

		ColorF m_color;

		explicit RingEffect(const Vec2& pos)
			: m_pos{ pos }
			, m_color{ Palette::Mediumseagreen } {}

		bool update(double t) override
		{
			// イージング
			const double e = EaseOutExpo(t);

			Circle{ m_pos, (e * 100) }.drawFrame((20.0 * (1.0 - e)), m_color);

			return (t < 1.0);
		}
	};

	Effect effect;
};

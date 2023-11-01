#pragma once
#include "Common.hpp"
#include "Aquarium.hpp"
#include "HPBar.hpp"
#include "LvIcon.hpp"
#include "FoodBtn.hpp"
#include "Garbage.hpp"
#include "Fish.hpp"
#include "Mousecursor.h"
class Game : public App::Scene
{
public:

	Game(const InitData& init);
	void update() override;
	void draw() const override;

private:
	const Texture m_backGround = TextureAsset(U"backGround");
	const int32 m_aqua_frameThick = 5;
	const int32 m_aqua_w = Scene::Width() - m_aqua_frameThick * 2;
	const int32 m_aqua_h = 400;
	const Vec2 m_aqua_pos = { Scene::Width() - (m_aqua_w + m_aqua_frameThick),
		Scene::Height() - (m_aqua_h + m_aqua_frameThick) };//左上の座標
	const Aquarium m_aqua{ m_backGround,m_aqua_pos,m_aqua_w,m_aqua_h,m_aqua_frameThick};

	const ColorF m_HPColor{ 0.8,0.2,0.2 };
	const int32 m_initialHP = 400;
	const int32 m_HPBarPosX = 200;
	const int32 m_HPBarPosY = 30;
	const int32 m_HPBarWidth = 470;
	const int32 m_HPBarHeight = 30;
	HPBar m_hpBar{ m_HPColor,m_initialHP };
	const Rect HPRect{ m_HPBarPosX,m_HPBarPosY,m_HPBarWidth,m_HPBarHeight };

	const Vec2 m_levelIconPos{ 10,10 };
	const double m_levelIconSize = 0.3;
	const int32 m_initialLevel = 1;
	LvIcon m_levelIcon{ m_levelIconPos,m_levelIconSize,m_initialLevel };

	const ColorF m_EXPColor{ 0, 0.851, 0.063 };
	const int32 m_initialEXP = 0;
	HPBar m_expBar{ m_EXPColor,m_initialEXP };
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

	const Image m_dust{ U"dotImages/Garbage.svg" };
	double m_accumulator = 0.0;
	Array<Garbage> m_garbages = Garbage::GenerateRandomPoints(m_SceneRect, 50.0, 80000.0, m_dust, m_aqua);

	const Image m_blueFishImage{ U"dotImages/blueFish.svg" };
	Fish m_fish1{ 200, 300, 100.0, m_blueFishImage, 2, m_aqua };

	//マウスカーソル
	const Image m_otete{ U"dotImages/foodFinger.svg" };
	const Image m_ami{ U"dotImages/ami.svg" };
	const Image m_allow{ U"dotImages/cursor.svg" };
	Mousecursor m_cursor{ 200.0, 300.0, m_otete, m_ami, m_allow, m_aqua };
	Array<Food> m_arrayFood; //Foodの配列を用意して、generateのたびに追加
};

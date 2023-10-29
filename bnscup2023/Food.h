#pragma once
#include<Siv3D.hpp>

class Food {
public:
	Food(float x, Vec2 aqua, int32 w, int32 h) {
		this->m_x = x;
		this->m_y = 60;//投下する際の初期y座標
		m_left = aqua.x;
		m_right = m_left + (float)w;
		m_texture = m_esaesa;
		m_maxY = aqua.y + h;
		m_trashTime = 0;
		m_ground = false;
		m_elapsedTime = 0;
		m_startTime = Random()*2;
	};
	void draw() const;
	void move();
	void removal();

	float m_x;
	float m_y;
	bool m_ground;
	float m_startTime;
	float m_trashTime;
	float m_elapsedTime;
	float m_maxY;
	float m_left;
	float m_right;
	Texture m_texture;
	const float m_dy = 1.5;//落下速度
	const Texture m_esaesa{ U"dotImages/food.svg" };
};

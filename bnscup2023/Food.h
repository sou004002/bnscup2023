#pragma once
#include "CollisionImage.hpp"
#include "Fish.hpp"
#include<Siv3D.hpp>

class Food {
public:
	Food(float x, Vec2 aqua, int32 w, int32 h, Aquarium aq)
		:m_x(x), m_y(120),
		m_esaesa((int32)m_x, (int32)m_y, 5, TextureAsset(U"food"), aq),
		m_left(aqua.x), m_right(m_left + (float)w), m_maxY(aqua.y + h), m_trashTime(0),
		m_ground(false), m_elapsedTime(0), m_startTime(Random() * 2), m_eaten(false),m_foodCircle(m_x-5, m_y-5, 10)
	{	//m_x = x;
		//m_y = 60;//投下する際の初期y座標
		//m_esaesa = CollisionImage((int32)m_x, (int32)m_y, 1.0, Image(U"dotImages/food.svg"));
		//m_left = aqua.x;
		//m_right = m_left + (float)w;
		//m_maxY = aqua.y + h;
		//m_trashTime = 0;
		//m_ground = false;
		//m_elapsedTime = 0;
		//m_startTime = Random()*2;
	};
	void draw() const;
	void move();
	void eaten(Fish fish);

	Food& operator=(const Food&);
	float m_x;
	float m_y;
	bool m_ground;
	float m_startTime;
	float m_trashTime;
	float m_elapsedTime;
	float m_maxY;
	float m_left;
	float m_right;
	bool m_eaten;
	double m_dx;
	const double m_dy = 1.5;
	Circle m_foodCircle;
	CollisionImage m_esaesa;
};

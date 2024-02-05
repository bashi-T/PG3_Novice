#pragma once
#include<Novice.h>
#include<Vector2.h>

class Player
{
private:
	Vector2 Position;

	Vector2 Speed;

	float PosX = 600.0f;
	float PosY = 300.0f;

	struct Bullet
	{
		Vector2 Pos;
		float Speed;
		int IsShot;
	};
	Bullet bullet;
public:
	Player();
	~Player();

	void Initialize();
	void Update();
	void Draw();

	const Bullet& GetBullet()const { return bullet; }
	const Vector2& GetPosition()const { return Position; }
	const Vector2& GetSpeed()const { return Speed; }
};

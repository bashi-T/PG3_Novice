#pragma once
#include<Novice.h>

class Player 
{
public:
	Player();
	~Player();
	void Initialize();
	void Update();
	void Draw();

private:
	struct Bullet
	{
		float PosX;
		float PosY;
		float Speed;
		int IsShot;
	} bullet = {0.0f, 0.0f, 0.0f, 0};
	struct Vector2
	{
		float x;
		float y;
	} Position = {0.0f, 0.0f};

	Vector2 Speed = {10.0f, 10.0f};
	float PosX = 600.0f;

public:
	Bullet GetBullet() { return bullet; }
	Vector2 GetPosition() { return Position; }
	Vector2 GetSpeed() { return Speed; }

};

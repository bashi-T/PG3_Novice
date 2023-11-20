#pragma once
#include<Vector2.h>
class Player 
{
public:
	Player();
	~Player();
	void PlayerMove(float vectorX, float vectorY);
	void BulletMove(float vectorX, float vectorY);
	void SetPosition(float pos, float number);
	void SetBulletPosition(float pos, float number);
	void SetIsShot(int i);
	Vector2 GetPosition() { return Position; }
	Vector2 GetSpeed() { return Speed; }

private:
	struct Bullet
	{
		float PosX = 600;
		float PosY = 300;
		float Speed = 10;
		int IsShot = 0;
	}bullet;

public:
	Bullet GetBullet() { return bullet; }

private:
	float PosX = 600;
	float PosY = 300;
	Vector2 Position
	{
		PosX,
		PosY
	};

	float velX = 10;
	float velY = 10;
	Vector2 Speed
	{
		velX,
		velY
	};


};

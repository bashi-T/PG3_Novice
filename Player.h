#pragma once
#include<Novice.h>
#include<Vector2.h>
class Player 
{
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

public:
	Player();
	~Player();
	void Init();
	void Update();
	void Draw();
	void MoveRight();
	void MoveLeft();
	Vector2 GetPosition() { return Position; }
	Vector2 GetSpeed() { return Speed; }

};

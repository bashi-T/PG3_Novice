#pragma once
#include <Novice.h>

class Enemy {
public:
	Enemy();
	~Enemy();

	void Initialize();
	void Update();
	void Draw();

private:
	//float PosX = 0;
	//float PosY = 0;
	struct Vector2
	{
		float x;
		float y;
	} Position = { 30.0f, 30.0f };

	int enespd = 5;
public:
	Vector2 GetPosition() { return Position; }

};

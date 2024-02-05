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
	struct Vector2
	{
		float x;
		float y;
	};
	Vector2 Position = { 30.0f, 30.0f };

	int enespd = 5;
public:
	Vector2 GetPosition() { return Position; }

};

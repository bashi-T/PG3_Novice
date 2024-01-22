#include "Enemy.h"

Enemy::Enemy() {}

Enemy::~Enemy() {}

void Enemy::Initialize()
{
	float PosX = 30;
	float PosY = 30;
	Position.x = PosX;
	Position.y = PosY;
	enespd = 5;
}

void Enemy::Update()
{
	if (Position.x == 1260)
	{
		enespd = -5;
	}
	if (Position.x == 20)
	{
		enespd = 5;
	}
	Position.x += enespd;
}

void Enemy::Draw()
{
	Novice::DrawEllipse(int(Position.x), int(Position.y), 20, 20, 0.0f, 0x0000FF, kFillModeSolid);
}

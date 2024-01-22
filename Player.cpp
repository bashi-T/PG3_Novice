#include "Player.h"

Player::Player() {}

Player::~Player() {}

void Player::Initialize()
{
	PosX = 600.0f;
	float PosY = 300.0f;
	Position.x = PosX;
	Position.y = PosY;
	Speed = {10.0f, 10.0f};
	bullet.IsShot = 0;
	bullet.PosX = Position.x;
	bullet.PosY = Position.y;
	bullet.Speed = 100.0f;
}

void Player::Update()
{
	char keys[256] = {0};
	char preKeys[256] = {0};
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
	if (keys[DIK_SPACE] &&
		preKeys[DIK_SPACE] == 0)
	{
		bullet.IsShot = 1;
	}

	if (bullet.PosY <= -25) {
		bullet.IsShot = 0;
		bullet.PosX = Position.x;
		bullet.PosY = Position.y;
	}

	if (keys[DIK_A])
	{
		Position.x -= Speed.x;
	}
	if (keys[DIK_D])
	{
		Position.x += Speed.x;
	}
	if (keys[DIK_W]) 
	{
		Position.y -= Speed.y;
	}
	if (keys[DIK_S])
	{
		Position.y += Speed.y;
	}

	if (Position.x >= 1260 && keys[DIK_D])
	{
		Position.x = 1260;
	}
	if (Position.y >= 700 && keys[DIK_S])
	{
		Position.y = 700;
	}
	if (Position.x <= 20 && keys[DIK_A])
	{
		Position.x = 20;
	}
	if (Position.y <= 20 && keys[DIK_W])
	{
		Position.y = 20;
	}


	if (bullet.IsShot == 1)
	{
		bullet.PosY += bullet.Speed;
	}
}

void Player::Draw()
{
	if (bullet.IsShot == 1)
	{
		Novice::DrawEllipse(
		    int(bullet.PosX),
			int(bullet.PosY),
			10,
			10,
			0.0f,
			0xFFFFFFFF,
		    kFillModeSolid);
	}
	Novice::DrawTriangle(
	    int(Position.x), int(Position.y),
		int(Position.x + 20), int(Position.y + 40),
	    int(Position.x - 20), int(Position.y + 40),
	    0xFF0000FF,
	    kFillModeSolid);
}


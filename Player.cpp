#include "Player.h"

Player::Player()
	//:Position({ 600.0f,300.0f })
	//,Speed({ 10.0f,0.0f })
	//,bullet({ {600.0f,300.0f},10.0f,0 })
{}

Player::~Player() {}

void Player::Initialize()
{
	PosX = 600.0f;
	PosY = 300.0f;
	Position = {
		PosX,
		PosY
	};
	Speed.x=10.0f;
	bullet.IsShot = 0;
	bullet.Pos.x = Position.x;
	bullet.Pos.y = Position.y;
	bullet.Speed = -20.0f;
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

	if (bullet.Pos.y <= -25) {
		bullet.IsShot = 0;
		bullet.Pos.x = Position.x;
		bullet.Pos.y = Position.y;
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
		bullet.Pos.y += bullet.Speed;
	}
}

void Player::Draw()
{
	if (bullet.IsShot == 1)
	{
		Novice::DrawEllipse(
		    int(bullet.Pos.x),
			int(bullet.Pos.y),
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


#include "Player.h"

Player::Player() {}

Player::~Player() {}

void Player::Init() {}

void Player::Update() {}

void Player::Draw() {}

void Player::PlayerMove(float vectorX, float vectorY)
{
	Position.x += vectorX;
	Position.y += vectorY;
}

void Player::BulletMove(float vectorX, float vectorY) {
	bullet.PosX += vectorX;
	bullet.PosY += vectorY;
}

void Player::SetPosition(float pos, float number) { pos = number; }

void Player::SetBulletPosition(float pos, float number) { pos = number; }

void Player::SetIsShot(int i) { bullet.IsShot = i; }


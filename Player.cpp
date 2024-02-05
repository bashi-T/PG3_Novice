#include "Player.h"

Player::Player() {}

Player::~Player() {}

void Player::Init() {}

void Player::Update() {}

void Player::Draw()
{
	Novice::DrawTriangle(
		int(Position.x),
		int(Position.y),
		int(Position.x + 20),
		int(Position.y + 40),
		int(Position.x - 20),
		int(Position.y + 40),
		0xFF0000FF,
		kFillModeSolid);
}

void Player::MoveRight()
{
	this->Position.x += this->Speed.x;
}

void Player::MoveLeft()
{
	this->Position.x -= this->Speed.x;
}


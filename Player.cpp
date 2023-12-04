#include "Player.h"

Player::Player() {}

Player::~Player() {}

void Player::Initialize() {}

void Player::Update() {
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		player->SetIsShot(1);
	}

	if (player->GetBullet().PosY <= -25) {
		player->SetIsShot(0);
	}

	if (keys[DIK_A]) {
		player->PlayerMove(-player->GetSpeed().x, 0);
	}
	if (keys[DIK_D]) {
		player->PlayerMove(player->GetSpeed().x, 0);
	}
	if (keys[DIK_W]) {
		player->PlayerMove(0, -player->GetSpeed().y);
	}
	if (keys[DIK_S]) {
		player->PlayerMove(0, player->GetSpeed().y);
	}

	if (player->GetPosition().x >= 1260 && keys[DIK_D]) {
		player->SetPosition(player->GetPosition().x, 1260);
	}
	if (player->GetPosition().y >= 700 && keys[DIK_S]) {
		player->SetPosition(player->GetPosition().y, 700);
	}
	if (player->GetPosition().x <= 20 && keys[DIK_A]) {
		player->SetPosition(player->GetPosition().x, 20);
	}
	if (player->GetPosition().y <= 20 && keys[DIK_W]) {
		player->SetPosition(player->GetPosition().y, 20);
	}

	DistX = player->GetBullet().PosX - enemyX;
	DistY = player->GetBullet().PosY - enemyY;

	enemyX += enespd;
	DIST = DistY * DistY + DistX * DistX;
	if (DIST <= 900 && DIST >= -900) {
		// bulletshot = 2;
	}
	// if (bulletshot == 2) {
	//	respown += -1;
	// }
	// if (respown == 0 && enemyX <= playerX)
	//{
	//	enespd = -10;
	// }
	// if (respown == 0 && enemyX > playerX)
	//{
	//	enespd = 10;
	// }
	// if (respown == 0)
	//{
	//	bulletshot = 0;
	//	respown = 120;
	// }

	if (player->GetBullet().IsShot == 0) {
		player->SetBulletPosition(player->GetBullet().PosY, player->GetPosition().y + 10.0f);
		player->SetBulletPosition(player->GetBullet().PosX, player->GetPosition().x);
	}
	if (player->GetBullet().IsShot == 1) {
		player->BulletMove(0, -player->GetBullet().Speed);
	}
	if (enemyX == 1260) {
		enespd = -5;
	}
	if (enemyX == 20) {
		enespd = 5;
	}
	// if (bulletshot == 2) {
	//	enespd = 0;
	// }
}

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


#include "StageScene.h"

void StageScene::Initialize()
{
	player_ = new Player;
	enemy_ = new Enemy;
	player_->Initialize();
	enemy_->Initialize();
}

void StageScene::Update() {
	player_->Update();
	enemy_->Update();
	DistX = player_->GetBullet().Pos.x - enemy_->GetPosition().x;
	DistY = player_->GetBullet().Pos.y - enemy_->GetPosition().y;

	DIST = DistY * DistY + DistX * DistX;
	if (DIST <= 900 && DIST >= -900)
	{
		sceneNo = CLEAR;
	}
}

void StageScene::Draw()
{
	player_->Draw();
	enemy_->Draw();
	Novice::ScreenPrintf(0, 0, "STAGESCENE");
}

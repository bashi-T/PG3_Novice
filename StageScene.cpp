#include "StageScene.h"

StageScene::StageScene()
{
}

void StageScene::Init()
{
	inputHandler_ = new InputHandler();

	inputHandler_->AssignMoveRightCommand2PressKeyD();
	inputHandler_->AssignMoveLeftCommand2PressKeyA();

	player_ = new Player();
}

void StageScene::Update()
{
	command_ = inputHandler_->HandleInput();

	if (this->command_) {
		command_->Exec(*player_);
	}
	player_->Update();
}

void StageScene::Draw()
{
	player_->Draw();
}

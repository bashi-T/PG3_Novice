#pragma once
#include<memory>
#include "IScene.h"
#include"InputManager.h"
#include"TitleScene.h"
#include"StageScene.h"
#include"ClearScene.h"
class GameManager
{
public:
	GameManager();
	~GameManager();
	int run();

private:
	std::unique_ptr<IScene> sceneArr_[3];

	int currentSceneNo_;
	int prevSceneNo_;
	InputManager* inputManager_;
};

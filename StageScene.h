#pragma once
#include"IScene.h"
#include"InputHandler.h"

class StageScene:public IScene
{
private:
	InputHandler* inputHandler_ = nullptr;
	Command* command_ = nullptr;
	Player* player_;

public:
	StageScene();

	void Init() override;
	void Update() override;
	void Draw() override;
};


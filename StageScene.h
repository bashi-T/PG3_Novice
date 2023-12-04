#pragma once
#include "IScene.h"
#include "InputManager.h"

class StageScene : public IScene {
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	InputManager* inputManager_;
};

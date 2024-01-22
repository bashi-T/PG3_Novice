#pragma once
#include "IScene.h"
#include"Player.h"
#include"Enemy.h"

class StageScene : public IScene {
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	Player* player_ = nullptr;
	Enemy* enemy_ = nullptr;
	float DistX;
	float DistY;
	float DIST;
};

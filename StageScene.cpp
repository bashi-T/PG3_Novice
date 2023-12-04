#include "StageScene.h"

void StageScene::Initialize() {}

void StageScene::Update() {
	if (inputManager_->GetPreKeys()[DIK_SPACE] == 0 && inputManager_->GetKeys()[DIK_SPACE]) {
		SceneNo = CLEAR;
	}
}

void StageScene::Draw() {}

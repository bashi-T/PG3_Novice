#include "ClearScene.h"

void ClearScene::Initialize() {}

void ClearScene::Update() {
	if (inputManager_->GetPreKeys()[DIK_SPACE] == 0 && inputManager_->GetKeys()[DIK_SPACE]) {
		SceneNo = TITLE;
	}
}

void ClearScene::Draw() {}

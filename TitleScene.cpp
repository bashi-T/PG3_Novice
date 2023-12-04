#include "TitleScene.h"

void TitleScene::Initialize() {}

void TitleScene::Update() {
	if (inputManager_->GetPreKeys()[DIK_SPACE] == 0 && inputManager_->GetKeys()[DIK_SPACE]) {
		SceneNo = STAGE;
	}
}

void TitleScene::Draw() {}

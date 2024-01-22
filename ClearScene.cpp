#include "ClearScene.h"

void ClearScene::Initialize() {}

void ClearScene::Update()
{
	char keys[256] = {0};
	char preKeys[256] = {0};
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) {
		sceneNo = TITLE;
	}
}

void ClearScene::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
	Novice::ScreenPrintf(0, 0, "CLEARSCENE");
}

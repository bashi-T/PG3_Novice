#include "InputManager.h"

void InputManager::Initialize() {}

void InputManager::Update() {
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
}

void InputManager::Draw() {}

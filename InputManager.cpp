#include "InputManager.h"

void InputManager::Initialize() {}

void InputManager::Update() {
	// �L�[���͂��󂯎��
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
}

void InputManager::Draw() {}

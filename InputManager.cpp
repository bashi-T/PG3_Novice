#include "InputManager.h"

void InputManager::Initialize() {}

void InputManager::Update() {
	// ƒL[“ü—Í‚ğó‚¯æ‚é
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
}

void InputManager::Draw() {}

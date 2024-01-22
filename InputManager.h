#pragma once
#include<Novice.h>

class InputManager
{
public:
	void Initialize();
	void Update();
	void Draw();

	const char (*GetKeys())[256] { return &keys; }
	const char (*GetPreKeys())[256] { return &preKeys; }

private:
	char keys[256] = {0};
	char preKeys[256] = {0};

};

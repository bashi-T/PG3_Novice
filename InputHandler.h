#pragma once
#include"Command.h"

class InputHandler
{
public:
	Command* HandleInput();

	void AssignMoveRightCommand2PressKeyD();
	void AssignMoveLeftCommand2PressKeyA();

private:
	Command* pressKeyD_;
	Command* pressKeyA_;
};


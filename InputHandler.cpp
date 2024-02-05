#include "InputHandler.h"

Command* InputHandler::HandleInput()
{
	if (Novice::CheckHitKey(DIK_D))
	{
		return pressKeyD_;
	}
	else if (Novice::CheckHitKey(DIK_A)) {
		return pressKeyA_;
	}
	return nullptr;
}

void InputHandler::AssignMoveRightCommand2PressKeyD()
{
	Command* command = new MoveRightCommand();
	this->pressKeyD_ = command;
}

void InputHandler::AssignMoveLeftCommand2PressKeyA()
{
	Command* command = new MoveLeftCommand();
	this->pressKeyA_ = command;
}

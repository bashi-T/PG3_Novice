#include <Novice.h>
#include"GameManager.h"

const char kWindowTitle[] = "LE2B_12_ツヅキバシマサミ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ライブラリの初期化
	GameManager* gameManager = new GameManager;
	Novice::Initialize(kWindowTitle, 1280, 720);

	gameManager->Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
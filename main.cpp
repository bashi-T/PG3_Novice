#include <Novice.h>
#include <math.h>
#include"Player.h"

const char kWindowTitle[] = "LC1A_16_ツヅキバシマサミ_AL1-2";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	int enemyX = 30;
	int enemyY = 30;
	int enespd = 5;
	float DistX;
	float DistY;
	float DIST;
	Player* player = new Player;
	// キー入力結果を受け取る箱

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0)
	{
		// フレームの開始
		Novice::BeginFrame();
		
		///
		/// ↓更新処理ここから
		///
		

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		if (player->GetBullet().IsShot == 1)
		{
			Novice::DrawEllipse(
			    int(player->GetBullet().PosX), int(player->GetBullet().PosY), 10, 10, 0.0f, 0xFFFFFFFF,
			    kFillModeSolid);
		}
		Novice::DrawTriangle(
		    int(player->GetPosition().x),
			int(player->GetPosition().y),
			int(player->GetPosition().x + 20),
		    int(player->GetPosition().y + 40),
			int(player->GetPosition().x - 20),
		    int(player->GetPosition().y + 40),
			0xFF0000FF,
			kFillModeSolid);
		if (player->GetBullet().IsShot < 2)
		{
			Novice::DrawEllipse(enemyX, enemyY, 20, 20, 0.0f, 0x0000FF, kFillModeSolid);
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
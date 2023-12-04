#include <Novice.h>
#include <math.h>
#include"Player.h"

const char kWindowTitle[] = "LC1A_16_ツヅキバシマサミ_AL1-2";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Player* player = new Player;
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0)
	{
		// フレームの開始
		Novice::BeginFrame();
		
		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		if (keys[DIK_A])
		{
			player->PlayerMove(-player->GetSpeed().x,0);
		}
		if (keys[DIK_D])
		{
			player->PlayerMove(player->GetSpeed().x,0);
		}
		if (keys[DIK_W])
		{
			player->PlayerMove(0, -player->GetSpeed().y);
		}
		if (keys[DIK_S])
		{
			player->PlayerMove(0, player->GetSpeed().y);
		}

		if (player->GetPosition().x >= 1260 && keys[DIK_D])
		{
			player->SetPosition(player->GetPosition().x, 1260);
		}
		if (player->GetPosition().y >= 700 && keys[DIK_S])
		{
			player->SetPosition(player->GetPosition().y, 700);
		}
		if (player->GetPosition().x <= 20 && keys[DIK_A])
		{
			player->SetPosition(player->GetPosition().x, 20);
		}
		if (player->GetPosition().y <= 20 && keys[DIK_W])
		{
			player->SetPosition(player->GetPosition().y, 20);
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::DrawTriangle(
		    int(player->GetPosition().x),
			int(player->GetPosition().y),
			int(player->GetPosition().x + 20),
		    int(player->GetPosition().y + 40),
			int(player->GetPosition().x - 20),
		    int(player->GetPosition().y + 40),
			0xFF0000FF,
			kFillModeSolid);

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
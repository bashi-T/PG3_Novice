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
		
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
		{
			player->SetIsShot(1);
			//player->SetBulletPosition(player->GetBullet().PosY, player->GetBullet().Speed);
		}

		if (player->GetBullet().PosY <= -25)
		{
			player->SetIsShot(0);
		}

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

		DistX = player->GetBullet().PosX - enemyX;
		DistY = player->GetBullet().PosY - enemyY;

		enemyX += enespd;
		DIST = DistY * DistY + DistX * DistX;
		if (DIST <= 900 && DIST >= -900)
		{
			//bulletshot = 2;
		}
		//if (bulletshot == 2) {
		//	respown += -1;
		//}
		//if (respown == 0 && enemyX <= playerX)
		//{
		//	enespd = -10;
		//}
		//if (respown == 0 && enemyX > playerX)
		//{
		//	enespd = 10;
		//}
		//if (respown == 0)
		//{
		//	bulletshot = 0;
		//	respown = 120;
		//}

		if (player->GetBullet().IsShot == 0)
		{
			player->SetBulletPosition(player->GetBullet().PosY, player->GetPosition().y + 10.0f);
			player->SetBulletPosition(player->GetBullet().PosX, player->GetPosition().x);
		}
		if (player->GetBullet().IsShot == 1)
		{
			player->BulletMove(0,-player->GetBullet().Speed);
		}
		if (enemyX == 1260)
		{
			enespd = -5;
		}
		if (enemyX == 20)
		{
			enespd = 5;
		}
		//if (bulletshot == 2) {
		//	enespd = 0;
		//}

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
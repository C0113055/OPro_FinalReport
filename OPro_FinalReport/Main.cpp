//
// Main.cpp
//

// @author C0113055

// DXライブラリのインポート
#include "DxLib.h"
// プレイヤークラスのインポート
#include "Player.h"

// ---------------- 定数 ----------------
// エネミーの最大弾数
const int MAX_ENEMY_SHOTS = 256;

// ---------------- グローバル変数 ----------------
// エネミーの弾存在フラグ
bool enemy_shots_flag[MAX_ENEMY_SHOTS];
// エネミーの弾の座標
float enemy_shots_x[MAX_ENEMY_SHOTS];
float enemy_shots_y[MAX_ENEMY_SHOTS];
// エネミーの弾のスピード
float enemy_shot_speed = 16.0f;

// ---------------- グローバル関数 ----------------
// 更新処理
void update();
// 描画処理
void draw();

// メイン処理
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // ウィンドウモードに設定
    ChangeWindowMode(true);
    // DXライブラリ初期化処理
    DxLib_Init();

    // プレイヤークラスのインスタンスを作成
    Player* player = new Player();

    // メインループ
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
    {
        // 更新処理
        update();
        player->update();
        // 描画処理
        draw();
        player->draw();
    }

    // プレイヤーインスタンスを削除
    delete player;

    // DXライブラリ終了処理
    DxLib_End();
    return 0;
}

// ---------------- グローバル関数 ----------------
// 更新処理
void update()
{

}

// 描画処理
void draw()
{
    // エネミーを描画
    DrawCircle(320, 96, 32, GetColor(255, 0, 0), true);
}

//
// Main.cpp
//

// @author C0113055

// DXライブラリのインポート
#include "DxLib.h"

// ---------------- 定数 ----------------
// プレイヤーの最大弾数
const int MAX_PLAYER_SHOTS = 32;
// エネミーの最大弾数
const int MAX_ENEMY_SHOTS = 256;

// ---------------- グローバル変数 ----------------
// プレイヤー座標
float player_x = 320.0f;
float player_y = 384.0f;
// プレイヤー移動スピード
float player_move_speed = 10.0f;
// プレイヤーの弾存在フラグ
bool player_shots_flag[MAX_PLAYER_SHOTS];
// プレイヤーの弾の座標
float player_shots_x[MAX_PLAYER_SHOTS];
float player_shots_y[MAX_PLAYER_SHOTS];
// プレイヤーの弾のスピード
float player_shot_speed = 16.0f;

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

    // メインループ
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
    {
        // 更新処理
        update();
        // 描画処理
        draw();
    }

    // DXライブラリ終了処理
    DxLib_End();
    return 0;
}

// ---------------- グローバル関数 ----------------
// 更新処理
void update()
{
    // プレイヤー移動
    if (CheckHitKey(KEY_INPUT_UP)) player_y -= player_move_speed;
    if (CheckHitKey(KEY_INPUT_DOWN)) player_y += player_move_speed;
    if (CheckHitKey(KEY_INPUT_RIGHT)) player_x += player_move_speed;
    if (CheckHitKey(KEY_INPUT_LEFT)) player_x -= player_move_speed;

    // プレイヤーの弾を発射する
    if (CheckHitKey(KEY_INPUT_Z))
    {
        // 全弾を検索
        for (int i = 0; i < MAX_PLAYER_SHOTS; ++i)
        {
            // 使われてない弾を検出
            if (!player_shots_flag[i])
            {
                // 弾を生成
                player_shots_flag[i] = true;
                player_shots_x[i] = player_x;
                player_shots_y[i] = player_y;
                // 検索を終了
                break;
            }
        }
    }

    // プレイヤーの弾を進める
    for (int i = 0; i < MAX_PLAYER_SHOTS; ++i)
    {
        // 存在してなければ次のループへ進める
        if (!player_shots_flag[i]) continue;

        // 弾を進める
        player_shots_y[i] -= player_shot_speed;

        // 画面外に出たら消す
        if (player_shots_y[i] < 0) player_shots_flag[i] = false;
    }
}

// 描画処理
void draw()
{
    // エネミーを描画
    DrawCircle(320, 96, 32, GetColor(255, 0, 0), true);

    // プレイヤーを描画
    DrawCircle(player_x, player_y, 16, GetColor(0, 0, 255), true);
    // プレイヤーの弾を描画
    for (int i = 0; i < MAX_PLAYER_SHOTS; ++i)
    {
        // 弾が存在するなら
        if (player_shots_flag[i])
        {
            // 弾を描画
            DrawCircle(player_shots_x[i], player_shots_y[i], 4, GetColor(255, 255, 255), true);
        }
    }
}

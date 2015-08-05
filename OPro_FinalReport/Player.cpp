//
// Player.cpp
//

// @author C0113055

// 自身のヘッダー
#include "Player.h"

Player::Player()
{

}

void Player::update()
{
    // プレイヤー移動
    if (CheckHitKey(KEY_INPUT_UP)) y -= move_speed;
    if (CheckHitKey(KEY_INPUT_DOWN)) y += move_speed;
    if (CheckHitKey(KEY_INPUT_RIGHT)) x += move_speed;
    if (CheckHitKey(KEY_INPUT_LEFT)) x -= move_speed;

    // プレイヤーの弾を発射する
    if (CheckHitKey(KEY_INPUT_Z))
    {
        // 全弾を検索
        for (int i = 0; i < MAX_PLAYER_SHOTS; ++i)
        {
            // 使われてない弾を検出
            if (!shots_flag[i])
            {
                // 弾を生成
                shots_flag[i] = true;
                shots_x[i] = x;
                shots_y[i] = y;
                // 検索を終了
                break;
            }
        }
    }

    // プレイヤーの弾を進める
    for (int i = 0; i < MAX_PLAYER_SHOTS; ++i)
    {
        // 存在してなければ次のループへ進める
        if (!shots_flag[i]) continue;

        // 弾を進める
        shots_y[i] -= shot_speed;

        // 画面外に出たら消す
        if (shots_y[i] < 0) shots_flag[i] = false;
    }
}

void Player::draw()
{
    // プレイヤーを描画
    DrawCircle(x, y, 16, GetColor(0, 0, 255), true);
    // プレイヤーの弾を描画
    for (int i = 0; i < MAX_PLAYER_SHOTS; ++i)
    {
        // 弾が存在するなら
        if (shots_flag[i])
        {
            // 弾を描画
            DrawCircle(shots_x[i], shots_y[i], 4, GetColor(255, 255, 255), true);
        }
    }
}

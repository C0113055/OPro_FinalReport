//
// Enemy.cpp
//

// @author C0113055

// 標準ライブラリをインポート
#include <iostream>
// 自身のヘッダー
#include "Enemy.h"

Enemy::Enemy(int level)
{
    this->level = level;

    // ショットスピード初期化
    for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
    {
        shots_speed[i] = 4.0f;
    }
}

void Enemy::update()
{
    // ローカル変数
    // 移動速度
    static float move_speed = 4.0f;
    // 移動時間
    static float move_time = 0.0f;
    // 次撃つ発射角
    static float next_angle = 0.0f;

    // -------- ↓問題の部分↓ --------
    switch (level)
    {
        // 弱レベル
        //   左右移動をし、遅い弾を全方位に法則的にばらまく
        case 0:
            // 移動
            x += move_speed;
            if (x < 0 ||
                x > 640)
            {
                move_speed *= -1;
            }
            // 弾速度セット
            for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
            {
                shots_speed[i] = 4;
            }
            next_angle += 10.0f;
            break;
        // 中レベル
        //   左右を滑らかに移動し、そこそこな速度の弾を全方位に法則的にばらまく
        case 1:
            // 移動
            x = 320 + std::sin(3.14f / 180.0f * move_time) * 320;
            if (x < 0 ||
                x > 640)
            {
                move_speed *= -1;
            }
            move_time++;
            // 弾速度セット
            for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
            {
                shots_speed[i] = 8;
            }
            next_angle += 10.0f;
            break;
        // 強レベル
        //   左右に瞬間移動をランダムに繰り返し、速い球を全方位にランダムにばらまく
        case 2:
            // 移動
            x = rand() % 641;
            // 弾速度セット
            for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
            {
                shots_speed[i] = 16;
            }
            // 発射角セット
            next_angle = rand() % 361;
            break;
    }
    // -------- ↑問題の部分↑ --------

    // 全弾を検索
    for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
    {
        // 使われてない弾を検出
        if (!shots_flag[i])
        {
            // 弾を生成
            shots_flag[i] = true;
            shots_x[i] = x;
            shots_y[i] = y;
            shots_angle[i] = next_angle;
            // 検索を終了
            break;
        }
    }

    // 弾を進める
    for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
    {
        // 存在してなければ次のループへ進める
        if (!shots_flag[i]) continue;

        // 弾を進める
        shots_x[i] += std::cos(3.14f/180.0f * shots_angle[i]) * shots_speed[i];
        shots_y[i] += std::sin(3.14f/180.0f* shots_angle[i]) * shots_speed[i];

        // 画面外に出たら消す
        if (shots_y[i] < 0 ||
            shots_y[i] > 480 ||
            shots_x[i] < 0 ||
            shots_x[i] > 640) shots_flag[i] = false;
    }
}

void Enemy::draw()
{
    // エネミーを描画
    DrawCircle(x, y, 32, GetColor(255, 0, 0), true);
    // 弾を描画
    for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
    {
        // 弾が存在するなら
        if (shots_flag[i])
        {
            // 弾を描画
            DrawCircle(shots_x[i], shots_y[i], 4, GetColor(255, 255, 0), true);
        }
    }
}

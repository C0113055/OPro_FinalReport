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

    // 挙動クラス初期化
    behavior = EnemyBehavior(new EasyStrategy());

    // ショットスピード初期化
    for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
    {
        shots_speed[i] = 4.0f;
    }
}

Enemy::~Enemy()
{

}

void Enemy::update()
{
    // ローカル変数
    // 移動速度
    static float move_speed = 4.0f;
    // 次撃つ発射角
    static float next_angle = 0.0f;

    // -------- ↓問題の部分↓ --------
    switch (level)
    {
        // 弱レベル
        //   左右移動をし、遅い弾を全方位に法則的にばらまく
        case 0:
            behavior.set_strategy(new EasyStrategy());
            behavior.do_behavior(&x, shots_speed, &next_angle);
            break;
        // 中レベル
        //   左右を滑らかに移動し、そこそこな速度の弾を全方位に法則的にばらまく
        case 1:
            behavior.set_strategy(new NormalStrategy());
            behavior.do_behavior(&x, shots_speed, &next_angle);
            break;
        // 強レベル
        //   左右に瞬間移動をランダムに繰り返し、速い球を全方位にランダムにばらまく
        case 2:
            behavior.set_strategy(new HardStrategy());
            behavior.do_behavior(&x, shots_speed, &next_angle);
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

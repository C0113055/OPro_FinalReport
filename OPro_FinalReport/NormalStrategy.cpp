//
// NormalStrategy
//

// @author C0113055

// 自身のヘッダー
#include "NormalStrategy.h"
// 標準ライブラリインポート
#include <iostream>

void NormalStrategy::behavior(float* x, float shots_speed[], float* next_angle)
{
    // 移動速度
    static float move_speed = 4.0f;
    // 移動時間
    static float move_time = 0.0f;

    // 移動
    *x = 320 + std::sin(3.14f / 180.0f * move_time) * 320;
    if (*x < 0 ||
        *x > 640)
    {
        move_speed *= -1;
    }
    move_time++;
    // 弾速度セット
    for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
    {
        shots_speed[i] = 8;
    }
    *next_angle += 10.0f;
}

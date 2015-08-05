//
// EasyStrategy
//

// @author C0113055

// 自身のヘッダー
#include "EasyStrategy.h"

void EasyStrategy::behavior(float* x, float shots_speed[], float* next_angle)
{
    // 移動速度
    static float move_speed = 4.0f;

    // 移動
    *x += move_speed;
    if (*x < 0 ||
        *x > 640)
    {
        move_speed *= -1;
    }
    // 弾速度セット
    for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
    {
        shots_speed[i] = 4;
    }
    *next_angle += 10.0f;
}

//
// HardStrategy
//

// @author C0113055

// 自身のヘッダー
#include "HardStrategy.h"
// 標準ライブラリインポート
#include <iostream>

void HardStrategy::behavior(float* x, float shots_speed[], float* next_angle)
{
    // 移動
    *x = rand() % 641;
    // 弾速度セット
    for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
    {
        shots_speed[i] = 16;
    }
    // 発射角セット
    *next_angle = rand() % 361;
}

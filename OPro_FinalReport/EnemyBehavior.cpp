//
// EnemyBehavior.cpp
//

// @author C0113055

// 自身のヘッダー
#include "EnemyBehavior.h"

EnemyBehavior::EnemyBehavior(Strategy* s)
{
    strategy = s;
}

EnemyBehavior::~EnemyBehavior()
{
    delete strategy;
}

void EnemyBehavior::set_strategy(Strategy* s)
{
    strategy = s;
}

void EnemyBehavior::do_behavior(float* x, float shots_speed[], float* next_angle)
{
    strategy->behavior(x, shots_speed, next_angle);
}

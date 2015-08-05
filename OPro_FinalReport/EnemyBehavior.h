//
// EasyBehavior.h
//

// @author C0113055

#pragma once

// DXライブラリのインポート
#include "DxLib.h"
// Strategyクラスのインポート
#include "Strategy.h"

// 敵挙動クラス
class EnemyBehavior
{
private:
    Strategy* strategy;

public:
    // コンストラクタ
    EnemyBehavior() {};
    EnemyBehavior(Strategy* s);
    // デストラクタ
    ~EnemyBehavior();

    void set_strategy(Strategy* s);

    void do_behavior(float* x, float shots_speed[], float* next_angle);
};

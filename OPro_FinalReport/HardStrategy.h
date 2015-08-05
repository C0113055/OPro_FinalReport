//
// HardStrategy.h
//

// @author C0113055

#pragma once

// DXライブラリのインポート
#include "DxLib.h"
// Strategyクラスのインポート
#include "Strategy.h"
// エネミークラスのインポート
#include "Enemy.h"

// 弱モードクラス
class HardStrategy : public Strategy
{
private:

public:
    HardStrategy() {};
    // 挙動
    void behavior(float* x, float shots_speed[], float* next_angle);
};

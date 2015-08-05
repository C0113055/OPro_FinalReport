//
// Strategy.h
//

// @author C0113055

#pragma once

// DXライブラリのインポート
#include "DxLib.h"

// Strategyクラス
class Strategy
{
private:

public:
    virtual void behavior(float* x, float shots_speed[], float* next_angle) = 0;
};

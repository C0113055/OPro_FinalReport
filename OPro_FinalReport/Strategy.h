//
// Strategy.h
//

// @author C0113055

#pragma once

// DX���C�u�����̃C���|�[�g
#include "DxLib.h"

// Strategy�N���X
class Strategy
{
private:

public:
    virtual void behavior(float* x, float shots_speed[], float* next_angle) = 0;
};

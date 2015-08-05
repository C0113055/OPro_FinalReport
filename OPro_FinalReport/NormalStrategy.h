//
// NormalStrategy.h
//

// @author C0113055

#pragma once

// DX���C�u�����̃C���|�[�g
#include "DxLib.h"
// Strategy�N���X�̃C���|�[�g
#include "Strategy.h"
// �G�l�~�[�N���X�̃C���|�[�g
#include "Enemy.h"

// �ヂ�[�h�N���X
class NormalStrategy : public Strategy
{
private:

public:
    NormalStrategy() {};
    // ����
    void behavior(float* x, float shots_speed[], float* next_angle);
};

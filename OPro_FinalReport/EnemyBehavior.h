//
// EasyBehavior.h
//

// @author C0113055

#pragma once

// DX���C�u�����̃C���|�[�g
#include "DxLib.h"
// Strategy�N���X�̃C���|�[�g
#include "Strategy.h"

// �G�����N���X
class EnemyBehavior
{
private:
    Strategy* strategy;

public:
    // �R���X�g���N�^
    EnemyBehavior() {};
    EnemyBehavior(Strategy* s);
    // �f�X�g���N�^
    ~EnemyBehavior();

    void set_strategy(Strategy* s);

    void do_behavior(float* x, float shots_speed[], float* next_angle);
};

//
// EasyStrategy.h
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
class EasyStrategy : public Strategy
{
private:

public:
    EasyStrategy() {};
    // ����
    void behavior(float* x, float shots_speed[], float* next_angle);
};

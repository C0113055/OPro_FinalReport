//
// HardStrategy
//

// @author C0113055

// ���g�̃w�b�_�[
#include "HardStrategy.h"
// �W�����C�u�����C���|�[�g
#include <iostream>

void HardStrategy::behavior(float* x, float shots_speed[], float* next_angle)
{
    // �ړ�
    *x = rand() % 641;
    // �e���x�Z�b�g
    for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
    {
        shots_speed[i] = 16;
    }
    // ���ˊp�Z�b�g
    *next_angle = rand() % 361;
}

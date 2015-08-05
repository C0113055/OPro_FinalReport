//
// NormalStrategy
//

// @author C0113055

// ���g�̃w�b�_�[
#include "NormalStrategy.h"
// �W�����C�u�����C���|�[�g
#include <iostream>

void NormalStrategy::behavior(float* x, float shots_speed[], float* next_angle)
{
    // �ړ����x
    static float move_speed = 4.0f;
    // �ړ�����
    static float move_time = 0.0f;

    // �ړ�
    *x = 320 + std::sin(3.14f / 180.0f * move_time) * 320;
    if (*x < 0 ||
        *x > 640)
    {
        move_speed *= -1;
    }
    move_time++;
    // �e���x�Z�b�g
    for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
    {
        shots_speed[i] = 8;
    }
    *next_angle += 10.0f;
}

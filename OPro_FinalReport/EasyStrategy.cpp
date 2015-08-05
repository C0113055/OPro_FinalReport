//
// EasyStrategy
//

// @author C0113055

// ���g�̃w�b�_�[
#include "EasyStrategy.h"

void EasyStrategy::behavior(float* x, float shots_speed[], float* next_angle)
{
    // �ړ����x
    static float move_speed = 4.0f;

    // �ړ�
    *x += move_speed;
    if (*x < 0 ||
        *x > 640)
    {
        move_speed *= -1;
    }
    // �e���x�Z�b�g
    for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
    {
        shots_speed[i] = 4;
    }
    *next_angle += 10.0f;
}

//
// Enemy.cpp
//

// @author C0113055

// �W�����C�u�������C���|�[�g
#include <iostream>
// ���g�̃w�b�_�[
#include "Enemy.h"

Enemy::Enemy(int level)
{
    this->level = level;

    // �V���b�g�X�s�[�h������
    for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
    {
        shots_speed[i] = 4.0f;
    }
}

void Enemy::update()
{
    // ���[�J���ϐ�
    // �ړ����x
    static float move_speed = 4.0f;
    // �ړ�����
    static float move_time = 0.0f;
    // �������ˊp
    static float next_angle = 0.0f;

    // -------- �����̕����� --------
    switch (level)
    {
        // �ヌ�x��
        //   ���E�ړ������A�x���e��S���ʂɖ@���I�ɂ΂�܂�
        case 0:
            // �ړ�
            x += move_speed;
            if (x < 0 ||
                x > 640)
            {
                move_speed *= -1;
            }
            // �e���x�Z�b�g
            for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
            {
                shots_speed[i] = 4;
            }
            next_angle += 10.0f;
            break;
        // �����x��
        //   ���E�����炩�Ɉړ����A���������ȑ��x�̒e��S���ʂɖ@���I�ɂ΂�܂�
        case 1:
            // �ړ�
            x = 320 + std::sin(3.14f / 180.0f * move_time) * 320;
            if (x < 0 ||
                x > 640)
            {
                move_speed *= -1;
            }
            move_time++;
            // �e���x�Z�b�g
            for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
            {
                shots_speed[i] = 8;
            }
            next_angle += 10.0f;
            break;
        // �����x��
        //   ���E�ɏu�Ԉړ��������_���ɌJ��Ԃ��A��������S���ʂɃ����_���ɂ΂�܂�
        case 2:
            // �ړ�
            x = rand() % 641;
            // �e���x�Z�b�g
            for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
            {
                shots_speed[i] = 16;
            }
            // ���ˊp�Z�b�g
            next_angle = rand() % 361;
            break;
    }
    // -------- �����̕����� --------

    // �S�e������
    for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
    {
        // �g���ĂȂ��e�����o
        if (!shots_flag[i])
        {
            // �e�𐶐�
            shots_flag[i] = true;
            shots_x[i] = x;
            shots_y[i] = y;
            shots_angle[i] = next_angle;
            // �������I��
            break;
        }
    }

    // �e��i�߂�
    for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
    {
        // ���݂��ĂȂ���Ύ��̃��[�v�֐i�߂�
        if (!shots_flag[i]) continue;

        // �e��i�߂�
        shots_x[i] += std::cos(3.14f/180.0f * shots_angle[i]) * shots_speed[i];
        shots_y[i] += std::sin(3.14f/180.0f* shots_angle[i]) * shots_speed[i];

        // ��ʊO�ɏo�������
        if (shots_y[i] < 0 ||
            shots_y[i] > 480 ||
            shots_x[i] < 0 ||
            shots_x[i] > 640) shots_flag[i] = false;
    }
}

void Enemy::draw()
{
    // �G�l�~�[��`��
    DrawCircle(x, y, 32, GetColor(255, 0, 0), true);
    // �e��`��
    for (int i = 0; i < MAX_ENEMY_SHOTS; ++i)
    {
        // �e�����݂���Ȃ�
        if (shots_flag[i])
        {
            // �e��`��
            DrawCircle(shots_x[i], shots_y[i], 4, GetColor(255, 255, 0), true);
        }
    }
}

//
// Player.cpp
//

// @author C0113055

// ���g�̃w�b�_�[
#include "Player.h"

Player::Player()
{

}

void Player::update()
{
    // �v���C���[�ړ�
    if (CheckHitKey(KEY_INPUT_UP)) y -= move_speed;
    if (CheckHitKey(KEY_INPUT_DOWN)) y += move_speed;
    if (CheckHitKey(KEY_INPUT_RIGHT)) x += move_speed;
    if (CheckHitKey(KEY_INPUT_LEFT)) x -= move_speed;

    // �v���C���[�̒e�𔭎˂���
    if (CheckHitKey(KEY_INPUT_Z))
    {
        // �S�e������
        for (int i = 0; i < MAX_PLAYER_SHOTS; ++i)
        {
            // �g���ĂȂ��e�����o
            if (!shots_flag[i])
            {
                // �e�𐶐�
                shots_flag[i] = true;
                shots_x[i] = x;
                shots_y[i] = y;
                // �������I��
                break;
            }
        }
    }

    // �v���C���[�̒e��i�߂�
    for (int i = 0; i < MAX_PLAYER_SHOTS; ++i)
    {
        // ���݂��ĂȂ���Ύ��̃��[�v�֐i�߂�
        if (!shots_flag[i]) continue;

        // �e��i�߂�
        shots_y[i] -= shot_speed;

        // ��ʊO�ɏo�������
        if (shots_y[i] < 0) shots_flag[i] = false;
    }
}

void Player::draw()
{
    // �v���C���[��`��
    DrawCircle(x, y, 16, GetColor(0, 0, 255), true);
    // �v���C���[�̒e��`��
    for (int i = 0; i < MAX_PLAYER_SHOTS; ++i)
    {
        // �e�����݂���Ȃ�
        if (shots_flag[i])
        {
            // �e��`��
            DrawCircle(shots_x[i], shots_y[i], 4, GetColor(255, 255, 255), true);
        }
    }
}

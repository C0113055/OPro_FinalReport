//
// Main.cpp
//

// @author C0113055

// DX���C�u�����̃C���|�[�g
#include "DxLib.h"

// ---------------- �萔 ----------------
// �v���C���[�̍ő�e��
const int MAX_PLAYER_SHOTS = 32;
// �G�l�~�[�̍ő�e��
const int MAX_ENEMY_SHOTS = 256;

// ---------------- �O���[�o���ϐ� ----------------
// �v���C���[���W
float player_x = 320.0f;
float player_y = 384.0f;
// �v���C���[�ړ��X�s�[�h
float player_move_speed = 10.0f;
// �v���C���[�̒e���݃t���O
bool player_shots_flag[MAX_PLAYER_SHOTS];
// �v���C���[�̒e�̍��W
float player_shots_x[MAX_PLAYER_SHOTS];
float player_shots_y[MAX_PLAYER_SHOTS];
// �v���C���[�̒e�̃X�s�[�h
float player_shot_speed = 16.0f;

// �G�l�~�[�̒e���݃t���O
bool enemy_shots_flag[MAX_ENEMY_SHOTS];
// �G�l�~�[�̒e�̍��W
float enemy_shots_x[MAX_ENEMY_SHOTS];
float enemy_shots_y[MAX_ENEMY_SHOTS];
// �G�l�~�[�̒e�̃X�s�[�h
float enemy_shot_speed = 16.0f;

// ---------------- �O���[�o���֐� ----------------
// �X�V����
void update();
// �`�揈��
void draw();

// ���C������
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // �E�B���h�E���[�h�ɐݒ�
    ChangeWindowMode(true);
    // DX���C�u��������������
    DxLib_Init();

    // ���C�����[�v
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
    {
        // �X�V����
        update();
        // �`�揈��
        draw();
    }

    // DX���C�u�����I������
    DxLib_End();
    return 0;
}

// ---------------- �O���[�o���֐� ----------------
// �X�V����
void update()
{
    // �v���C���[�ړ�
    if (CheckHitKey(KEY_INPUT_UP)) player_y -= player_move_speed;
    if (CheckHitKey(KEY_INPUT_DOWN)) player_y += player_move_speed;
    if (CheckHitKey(KEY_INPUT_RIGHT)) player_x += player_move_speed;
    if (CheckHitKey(KEY_INPUT_LEFT)) player_x -= player_move_speed;

    // �v���C���[�̒e�𔭎˂���
    if (CheckHitKey(KEY_INPUT_Z))
    {
        // �S�e������
        for (int i = 0; i < MAX_PLAYER_SHOTS; ++i)
        {
            // �g���ĂȂ��e�����o
            if (!player_shots_flag[i])
            {
                // �e�𐶐�
                player_shots_flag[i] = true;
                player_shots_x[i] = player_x;
                player_shots_y[i] = player_y;
                // �������I��
                break;
            }
        }
    }

    // �v���C���[�̒e��i�߂�
    for (int i = 0; i < MAX_PLAYER_SHOTS; ++i)
    {
        // ���݂��ĂȂ���Ύ��̃��[�v�֐i�߂�
        if (!player_shots_flag[i]) continue;

        // �e��i�߂�
        player_shots_y[i] -= player_shot_speed;

        // ��ʊO�ɏo�������
        if (player_shots_y[i] < 0) player_shots_flag[i] = false;
    }
}

// �`�揈��
void draw()
{
    // �G�l�~�[��`��
    DrawCircle(320, 96, 32, GetColor(255, 0, 0), true);

    // �v���C���[��`��
    DrawCircle(player_x, player_y, 16, GetColor(0, 0, 255), true);
    // �v���C���[�̒e��`��
    for (int i = 0; i < MAX_PLAYER_SHOTS; ++i)
    {
        // �e�����݂���Ȃ�
        if (player_shots_flag[i])
        {
            // �e��`��
            DrawCircle(player_shots_x[i], player_shots_y[i], 4, GetColor(255, 255, 255), true);
        }
    }
}

//
// Main.cpp
//

// @author C0113055

// DX���C�u�����̃C���|�[�g
#include "DxLib.h"
// �v���C���[�N���X�̃C���|�[�g
#include "Player.h"

// ---------------- �萔 ----------------
// �G�l�~�[�̍ő�e��
const int MAX_ENEMY_SHOTS = 256;

// ---------------- �O���[�o���ϐ� ----------------
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

    // �v���C���[�N���X�̃C���X�^���X���쐬
    Player* player = new Player();

    // ���C�����[�v
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
    {
        // �X�V����
        update();
        player->update();
        // �`�揈��
        draw();
        player->draw();
    }

    // �v���C���[�C���X�^���X���폜
    delete player;

    // DX���C�u�����I������
    DxLib_End();
    return 0;
}

// ---------------- �O���[�o���֐� ----------------
// �X�V����
void update()
{

}

// �`�揈��
void draw()
{
    // �G�l�~�[��`��
    DrawCircle(320, 96, 32, GetColor(255, 0, 0), true);
}

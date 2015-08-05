//
// Main.cpp
//

// @author C0113055

// DX���C�u�����̃C���|�[�g
#include "DxLib.h"
// �v���C���[�N���X�̃C���|�[�g
#include "Player.h"
// �G�l�~�[�N���X�̃C���|�[�g
#include "Enemy.h"

// ���C������
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // �E�B���h�E���[�h�ɐݒ�
    ChangeWindowMode(true);
    // DX���C�u��������������
    DxLib_Init();

    // �v���C���[�N���X�̃C���X�^���X���쐬
    //   -------- ����̃��|�[�g�ɂ͊���Ɗ֌W�Ȃ� --------
    Player* player = new Player();
    // �G�l�~�[�N���X�̃C���X�^���X���쐬
    //   -------- ����Strategy�p�^�[����p����Ƃ��� --------
    Enemy* enemy = new Enemy(2);

    // ���C�����[�v
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
    {
        // �X�V����
        player->update();
        enemy->update();
        // �`�揈��
        player->draw();
        enemy->draw();
    }

    // �v���C���[�C���X�^���X���폜
    delete player;
    // �G�l�~�[�N���X�̃C���X�^���X���폜
    delete enemy;

    // DX���C�u�����I������
    DxLib_End();
    return 0;
}

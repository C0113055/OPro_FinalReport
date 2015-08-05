//
// Player.h
//

// @author C0113055

#pragma once

// DX���C�u�����̃C���|�[�g
#include "DxLib.h"

// �v���C���[�̍ő�e��
const int MAX_PLAYER_SHOTS = 32;

// �v���C���[�N���X
class Player
{
private:
    // �v���C���[���W
    float x = 320.0f;
    float y = 384.0f;
    // �v���C���[�ړ��X�s�[�h
    float move_speed = 10.0f;
    // �v���C���[�̒e���݃t���O
    bool shots_flag[MAX_PLAYER_SHOTS];
    // �v���C���[�̒e�̍��W
    float shots_x[MAX_PLAYER_SHOTS];
    float shots_y[MAX_PLAYER_SHOTS];
    // �v���C���[�̒e�̃X�s�[�h
    float shot_speed = 16.0f;

public:
    // �R���X�g���N�^
    Player();
    // �X�V����
    void update();
    // �`�揈��
    void draw();
};

//
// Enemy.h
//

// @author C0113055

#pragma once

// DX���C�u�����̃C���|�[�g
#include "DxLib.h"
// Strategy�N���X�̃C���|�[�g
#include "Strategy.h"
#include "EasyStrategy.h"
#include "NormalStrategy.h"
#include "HardStrategy.h"
#include "EnemyBehavior.h"

// �G�l�~�[�̍ő�e��
const int MAX_ENEMY_SHOTS = 256;

// �G�l�~�[�N���X
class Enemy
{
private:
    // context�����̃N���X�ϐ����쐬
    EnemyBehavior behavior;

    // �G�l�~�[�̃��x��
    int level = 0;
    // �v���C���[���W
    float x = 320.0f;
    float y = 96.0f;
    // �G�l�~�[�̒e���݃t���O
    bool shots_flag[MAX_ENEMY_SHOTS];
    // �G�l�~�[�̒e�̍��W
    float shots_x[MAX_ENEMY_SHOTS];
    float shots_y[MAX_ENEMY_SHOTS];
    // �G�l�~�[�̒e�̃X�s�[�h
    float shots_speed[MAX_ENEMY_SHOTS];
    // �e�̔��ˊp
    float shots_angle[MAX_ENEMY_SHOTS];

public:
    // �R���X�g���N�^
    //   �����ɋ���������
    Enemy() {};
    Enemy(int level);
    // �f�X�g���N�^
    ~Enemy();

    // �X�V����
    void update();
    // �`�揈��
    void draw();
};

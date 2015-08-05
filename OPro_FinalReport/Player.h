//
// Player.h
//

// @author C0113055

#pragma once

// DXライブラリのインポート
#include "DxLib.h"

// プレイヤーの最大弾数
const int MAX_PLAYER_SHOTS = 32;

// プレイヤークラス
class Player
{
private:
    // プレイヤー座標
    float x = 320.0f;
    float y = 384.0f;
    // プレイヤー移動スピード
    float move_speed = 10.0f;
    // プレイヤーの弾存在フラグ
    bool shots_flag[MAX_PLAYER_SHOTS];
    // プレイヤーの弾の座標
    float shots_x[MAX_PLAYER_SHOTS];
    float shots_y[MAX_PLAYER_SHOTS];
    // プレイヤーの弾のスピード
    float shot_speed = 16.0f;

public:
    // コンストラクタ
    Player();
    // 更新処理
    void update();
    // 描画処理
    void draw();
};

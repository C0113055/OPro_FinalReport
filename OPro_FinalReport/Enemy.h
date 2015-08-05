//
// Enemy.h
//

// @author C0113055

// DXライブラリのインポート
#include "DxLib.h"

// エネミーの最大弾数
const int MAX_ENEMY_SHOTS = 256;

// エネミークラス
class Enemy
{
private:
    // エネミーのレベル
    int level = 0;
    // プレイヤー座標
    float x = 320.0f;
    float y = 96.0f;
    // エネミーの弾存在フラグ
    bool shots_flag[MAX_ENEMY_SHOTS];
    // エネミーの弾の座標
    float shots_x[MAX_ENEMY_SHOTS];
    float shots_y[MAX_ENEMY_SHOTS];
    // エネミーの弾のスピード
    float shots_speed[MAX_ENEMY_SHOTS];
    // 弾の発射角
    float shots_angle[MAX_ENEMY_SHOTS];

public:
    // コンストラクタ
    //   引数に強さを入れる
    Enemy(int level);

    // 更新処理
    void update();
    // 描画処理
    void draw();
};

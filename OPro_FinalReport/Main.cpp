//
// Main.cpp
//

// @author C0113055

// DXライブラリのインポート
#include "DxLib.h"
// プレイヤークラスのインポート
#include "Player.h"
// エネミークラスのインポート
#include "Enemy.h"

// メイン処理
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // ウィンドウモードに設定
    ChangeWindowMode(true);
    // DXライブラリ初期化処理
    DxLib_Init();

    // プレイヤークラスのインスタンスを作成
    //   -------- 今回のレポートには割りと関係ない --------
    Player* player = new Player();
    // エネミークラスのインスタンスを作成
    //   -------- 今回Strategyパターンを用いるところ --------
    Enemy* enemy = new Enemy(2);

    // メインループ
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
    {
        // 更新処理
        player->update();
        enemy->update();
        // 描画処理
        player->draw();
        enemy->draw();
    }

    // プレイヤーインスタンスを削除
    delete player;
    // エネミークラスのインスタンスを削除
    delete enemy;

    // DXライブラリ終了処理
    DxLib_End();
    return 0;
}

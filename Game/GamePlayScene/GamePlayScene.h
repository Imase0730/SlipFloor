//--------------------------------------------------------------------------------------
// File: GamePlayScene.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Player.h"
#include "Enemy.h"
#include "BulletManager.h"

// クラスの前方宣言
class Game;

// タイトルシーン
class GamePlayScene
{
	// 列挙型の定義 -----------------------------------------------------
private:


	// クラス定数の宣言 -------------------------------------------------
public:


	// データメンバの宣言 -----------------------------------------------
private:

	// このシーンを含むゲームオブジェクトへのポインタ
	Game* m_pGame;

	// プレイヤーの絵のグラフィックハンドル
	int m_ghPlayer;

	// 敵の絵のグラフィックハンドル
	int m_ghEnemy;

	// 弾の絵のグラフィックハンドル
	int m_ghBullet;

	// プレイヤー
	Player m_player;

	// プレイヤーの弾のマネージャー
	BulletManager m_playerBulletManager;

	// 敵
	Enemy m_enemy;

	// 敵の弾のマネージャー
	BulletManager m_enemyBulletManager;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	GamePlayScene(Game* pGame);

	// デストラクタ
	~GamePlayScene();

	// 初期化処理
	void Initialize();

	// 更新処理
	void Update(int keyCondition, int keyTrigger);

	// 描画処理
	void Render();

	// 終了処理
	void Finalize();

};

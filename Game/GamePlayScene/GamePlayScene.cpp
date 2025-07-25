//--------------------------------------------------------------------------------------
// File: GamePlayScene.cpp
//
//--------------------------------------------------------------------------------------
#include "GamePlayScene.h"
#include "Game/Game.h"
#include "Game/Screen.h"
#include "Game/Collision.h"

// コンストラクタ
GamePlayScene::GamePlayScene(Game* pGame)
	: m_pGame{ pGame }
	, m_ghPlayer{ -1 }
	, m_ghEnemy{ -1 }
	, m_ghBullet{ -1 }
	, m_player{}
	, m_playerBulletManager{}
	, m_enemy{ &m_player }
	, m_enemyBulletManager{}
{
}

// デストラクタ
GamePlayScene::~GamePlayScene()
{
}

// 初期化処理
void GamePlayScene::Initialize()
{
	// 絵の読み込み
	m_ghPlayer = LoadGraph(L"Resources/Textures/Player.png");
	m_ghEnemy = LoadGraph(L"Resources/Textures/Enemy.png");
	m_ghBullet = LoadGraph(L"Resources/Textures/Bullet.png");

	// プレイヤーの初期化
	m_player.Initialize();

	// プレイヤーの弾のマネージャーの初期化
	m_playerBulletManager.Initialize(10);

	// 敵の初期化
	m_enemy.Initialize();

	// 敵の弾のマネージャーの初期化
	m_enemyBulletManager.Initialize(10);

}

// 更新処理
void GamePlayScene::Update(int keyCondition, int keyTrigger)
{
	// プレイヤーの更新
	m_player.Update(keyCondition, keyTrigger, m_playerBulletManager);

	// プレイヤーの弾のマネージャーの更新
	m_playerBulletManager.Update();

	// 敵の更新
	m_enemy.Update(m_enemyBulletManager);

	// 敵の弾のマネージャーの更新
	m_enemyBulletManager.Update();

	// プレイヤーと敵の衝突判定
	if (IsCircleColliding(m_player.GetBoundingCircle(), m_enemy.GetBoundingCircle()))
	{
		// 重ならないように位置を修正する
		BoundingCircle player = m_player.GetBoundingCircle();
		BoundingCircle enemy = m_enemy.GetBoundingCircle();
		ResolveOverlap(&player, &enemy);
		m_player.SetPosition(player.center);
		m_enemy.SetPosition(enemy.center);
	}
}

// 描画処理
void GamePlayScene::Render()
{
	// プレイヤーの描画
	m_player.Render(m_ghPlayer);

	// 敵の描画
	m_enemy.Render(m_ghEnemy);

	// プレイヤーの弾のマネージャーの描画
	m_playerBulletManager.Render(m_ghBullet);

	// 敵の弾のマネージャーの描画
	m_enemyBulletManager.Render(m_ghBullet);

	DrawFormatString(10, 30, GetColor(255, 255, 255), L"GamePlayシーン");
}
 
// 終了処理
void GamePlayScene::Finalize()
{
	// 読み込んだ絵の解放
	DeleteGraph(m_ghPlayer);
	DeleteGraph(m_ghEnemy);
	DeleteGraph(m_ghBullet);
}


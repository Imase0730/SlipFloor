//--------------------------------------------------------------------------------------
// File: GamePlayScene.cpp
//
//--------------------------------------------------------------------------------------
#include "GamePlayScene.h"
#include "Game/Game.h"
#include "Game/Screen.h"

// コンストラクタ
GamePlayScene::GamePlayScene(Game* pGame)
	: m_pGame{ pGame }
	, m_ghPlayer{ -1 }
	, m_ghBullet{ -1 }
	, m_player{}
	, m_bullet{}
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
	m_ghBullet = LoadGraph(L"Resources/Textures/Bullet.png");

	// プレイヤーの初期化
	m_player.Initialize();
}

// 更新処理
void GamePlayScene::Update(int keyCondition, int keyTrigger)
{
	// プレイヤーの更新
	m_player.Update(keyCondition, keyTrigger);
}

// 描画処理
void GamePlayScene::Render()
{
	// プレイヤーの描画
	m_player.Render(m_ghPlayer);

	// 弾の描画
	m_bullet.Render(m_ghBullet);

	DrawFormatString(10, 30, GetColor(255, 255, 255), L"GamePlayシーン");
}
 
// 終了処理
void GamePlayScene::Finalize()
{
	// 読み込んだ絵の解放
	DeleteGraph(m_ghPlayer);
	DeleteGraph(m_ghBullet);
}


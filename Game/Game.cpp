﻿/**
 * @file   Game.cpp
 *
 * @brief  ゲーム全体に関するソースファイル
 *
 * @author 制作者名
 *
 * @date   日付
 */

 // ヘッダファイルの読み込み ===================================================
#include "Game.h"

#include "Game/Screen.h"




// メンバ関数の定義 ===========================================================
/**
 * @brief デフォルトコンストラクタ
 *
 * @param なし
 */
Game::Game()
	: m_key{ 0 }
	, m_oldKey{ 0 }
	, m_ghScreen{ -1 }
	, m_currentSceneID{ SceneID::None }
	, m_requestedSceneID{ SceneID::None }
	, m_gamePlayScene{ this }
{
	// 乱数の初期値を設定
	SRand(static_cast<int>(time(nullptr)));
}



/**
 * @brief デストラクタ
 */
Game::~Game()
{

}



/**
 * @brief 初期化処理
 *
 * @param なし
 *
 * @return なし
 */
void Game::Initialize()
{
	// ゲームの初期化
	// 
	// 描画先のグラフィックを作成する
	m_ghScreen = MakeScreen(Screen::GAME_WIDTH, Screen::GAME_HEIGHT, false);

	// スタートシーンの設定
	SetStartScene(SceneID::GamePlay);
}



/**
 * @brief 更新処理
 *
 * @param なし
 *
 * @return なし
 */
void Game::Update(float elapsedTime)
{
	// ゲームの更新

	// キー入力の取得
	m_oldKey = m_key;
	m_key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	// シーンの切り替えリクエストがある？
	if (m_requestedSceneID != SceneID::None)
	{
		// シーンを切り替える
		ChangeScene();
	}

	// 現在のシーンを更新
	UpdateCurrentScene(m_key, ~m_oldKey & m_key);
}



/**
 * @brief 描画処理
 *
 * @param[in] なし
 *
 * @return なし
 */
void Game::Render()
{
	// ゲームの描画

	// 作成した画像を描画対象にする
	SetDrawScreen(m_ghScreen);

	// クリア色を設定
	SetBackgroundColor(0, 0, 0);

	// 描画対象をクリア
	ClearDrawScreen();

	// ----- 描画（始まり）----- //

	// 現在のシーンを描画
	RenderCurrentScene();

	// ----- 描画（終わり） ----- //

	// 描画対象を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	// 描画対象画像を描画する
	int width = static_cast<int>(Screen::GAME_WIDTH * Screen::ZOOM_RATIO);
	int height = static_cast<int>(Screen::GAME_HEIGHT * Screen::ZOOM_RATIO);
	int x = Screen::WIDTH / 2 - width / 2;
	int y = Screen::HEIGHT / 2 - height / 2;
	DrawExtendGraph(x, y, x + width, y + height, m_ghScreen, FALSE);
}



/**
 * @brief 終了処理
 *
 * @param なし
 *
 * @return なし
 */
void Game::Finalize()
{
	// ゲームの終了処理

	// 現在のシーンの終了処理
	FinalizeCurrentScene();
}

// シーン変更の要求
void Game::RequestSceneChange(SceneID nextSceneID)
{
	m_requestedSceneID = nextSceneID;
}

// 開始シーンの設定
void Game::SetStartScene(SceneID startSceneID)
{
	m_currentSceneID = startSceneID;
	InitializeCurrentScene();
}

// シーンの変更
void Game::ChangeScene()
{
	// 現在のシーンを終了させる
	FinalizeCurrentScene();
	// シーンIDの変更
	m_currentSceneID = m_requestedSceneID;
	// 新しいシーンを初期化する
	InitializeCurrentScene();
	// シーンの変更が終わったので変更要求をリセット
	m_requestedSceneID = SceneID::None;
}

// 現在のシーンの初期化処理
void Game::InitializeCurrentScene()
{
	switch (m_currentSceneID)
	{
	case SceneID::GamePlay:		// ゲームプレイ
		m_gamePlayScene.Initialize();
		break;
	default:
		break;
	}
}

// 現在のシーンの更新処理
void Game::UpdateCurrentScene(int keyCondition, int keyTrigger)
{
	switch (m_currentSceneID)
	{
	case SceneID::GamePlay:		// ゲームプレイ
		m_gamePlayScene.Update(keyCondition, keyTrigger);
		break;
	default:
		break;
	}
}

// 現在のシーンの描画処理
void Game::RenderCurrentScene()
{
	switch (m_currentSceneID)
	{
	case SceneID::GamePlay:		// ゲームプレイ
		m_gamePlayScene.Render();
		break;
	default:
		break;
	}

}

// 現在のシーンの終了処理
void Game::FinalizeCurrentScene()
{
	switch (m_currentSceneID)
	{
	case SceneID::GamePlay:		// ゲームプレイ
		m_gamePlayScene.Finalize();
		break;
	default:
		break;
	}
}
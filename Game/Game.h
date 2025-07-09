/**
 * @file   Game.h
 *
 * @brief  ゲーム全体に関するヘッダファイル
 *
 * @author 制作者名
 *
 * @date   日付
 */

 // 多重インクルードの防止 =====================================================
#pragma once

#include "GamePlayScene/GamePlayScene.h"


// ヘッダファイルの読み込み ===================================================




// クラスの宣言 ===============================================================




// クラスの定義 ===============================================================
/**
 * @brief ゲーム
 */
class Game
{
	// 列挙型の定義 -------------------------------------------------
public:

	// シーンID
	enum class SceneID
	{
		None = -1,
		GamePlay,		// ゲームプレイ
	};

	// クラス定数の宣言 -------------------------------------------------
public:
	// システム関連
	static constexpr const wchar_t* TITLE = L"Slip Floor";   ///< ゲームタイトル



	// データメンバの宣言 -----------------------------------------------
private:
	// 入力関連
	int m_key;       ///< 現在のキー情報
	int m_oldKey;    ///< 前回のキー情報

	// 描画先のグラフィックハンドル
	int m_ghScreen;

	SceneID m_currentSceneID;	// 現在のシーンID
	SceneID m_requestedSceneID;	// 変更要求のシーンID

	// シーンオブジェクト
	GamePlayScene m_gamePlayScene;	// ゲームプレイシーン


	// メンバ関数の宣言 -------------------------------------------------
	// コンストラクタ/デストラクタ
public:
	// コンストラクタ
	Game();

	// デストラクタ
	~Game();


	// 操作
public:
	// 初期化処理
	void Initialize();

	// 更新処理
	void Update(float elapsedTime);

	// 描画処理
	void Render();

	// 終了処理
	void Finalize();

	// シーン変更の要求
	void RequestSceneChange(SceneID nextSceneID);

private:

	// 開始シーンの設定
	void SetStartScene(SceneID startSceneID);

	// シーンの変更
	void ChangeScene();

	// 現在のシーンの初期化処理
	void InitializeCurrentScene();

	// 現在のシーンの更新処理
	void UpdateCurrentScene(int keyCondition, int keyTrigger);

	// 現在のシーンの描画処理
	void RenderCurrentScene();

	// 現在のシーンの終了処理
	void FinalizeCurrentScene();

};

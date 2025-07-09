#pragma once

#include "Game/GameMath.h"

// プレイヤークラス
class Player
{
	// メンバ変数 ---------------------------------------
private:

	// 位置
	Vector2D m_position;

	// 向き
	float m_angleRad;

	// メンバ関数 ---------------------------------------
public:

	// コンストラクタ
	Player();

	// 初期化関数
	void Initialize();

	// 更新処理
	void Update(int keyCondition, int keyTrigger);

	// 描画処理
	void Render(int ghPlayer);

};

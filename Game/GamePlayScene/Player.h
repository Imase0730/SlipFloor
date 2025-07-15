#pragma once

#include "Game/GameMath.h"
#include "BulletManager.h"

// プレイヤークラス
class Player
{
	// 定数宣言 -----------------------------------------
private:

	// 最大移動速度
	static constexpr float MOVE_SPEED_MAX = 4.0f;

	// 移動時の加速度
	static constexpr float MOVE_ACCELERATION = 0.1f;

	// メンバ変数 ---------------------------------------
private:

	// 位置
	Vector2D m_position;

	// 向き
	float m_angleRad;

	// 速度
	Vector2D m_velocity;

	// 加速度
	Vector2D m_acceleration;

	// メンバ関数 ---------------------------------------
public:

	// コンストラクタ
	Player();

	// 初期化関数
	void Initialize();

	// 更新処理
	void Update(int keyCondition, int keyTrigger, BulletManager& bulletManager);

	// 描画処理
	void Render(int ghPlayer);

};

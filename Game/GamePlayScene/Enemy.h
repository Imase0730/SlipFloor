#pragma once

#include "Game/GameMath.h"
#include "BulletManager.h"
#include "Player.h"
#include "Game/Collision.h"

// 敵クラス
class Enemy
{
	// 定数宣言 -----------------------------------------
private:

	// 半径
	static constexpr float RADIUS = 16.0f;

	// 最大移動速度
	static constexpr float MOVE_SPEED_MAX = 4.0f;

	// 移動時の加速度
	static constexpr float MOVE_ACCELERATION = 0.1f;

	// プレイヤーに近づく距離
	static constexpr float APPROACH_DISTANCE = 100.0f;

	// 回転角度
	static constexpr float TURN_ANGLE = 2.0f;

	// 敵の視野角
	static constexpr float VIEW_ANGLE = 60.0f;

	// 弾の発射間隔
	static constexpr int SHOOT_INTERVAL_FRAME = 60;

	// 弾を発射する距離
	static constexpr float SHOOT_DISTANCE = 300.0f;

	// 弾を発射する視野角
	static constexpr float SHOOT_VIEW_ANGLE = 20.0f;

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

	// プレイヤーへのポインタ
	Player* m_pPlayer;

	// 弾を発射する間隔のフレーム数
	int m_shootDelayFrame;

	// メンバ関数 ---------------------------------------
public:

	// コンストラクタ
	Enemy(Player* pPlayer);

	// 初期化関数
	void Initialize();

	// 更新処理
	void Update(BulletManager& bulletManager);

	// 描画処理
	void Render(int ghEnemy);

	// 位置を設定する関数
	void SetPosition(Vector2D position) { m_position = position; }

	// 衝突判定用の円情報を取得する関数
	BoundingCircle GetBoundingCircle() { return BoundingCircle{ m_position, RADIUS }; }

};

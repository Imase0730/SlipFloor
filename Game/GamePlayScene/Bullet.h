#pragma once

#include "Game/GameMath.h"

// 弾クラス
class Bullet
{
	// 列挙型の定義 -----------------------------------------------------
public:

	// クラス定数の宣言 -------------------------------------------------
public:

	// 弾の速さ
	static constexpr float MOVE_SPEED = 5.0f;

	// 弾の大きさ（８ドット）
	static constexpr int BULLET_SIZE = 8;

	// データメンバの宣言 -----------------------------------------------
private:

	// アクティブならtrueを設定
	bool m_isActive;

	// 位置
	Vector2D m_position;

	// 速度
	Vector2D m_velocity;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	Bullet();

	// 更新関数
	void Update();

	// 描画関数
	void Render(int ghBullet);

	// 敵がアクティブか調べる関数
	bool IsActive() const { return m_isActive; }

	// 弾を発射する関数
	void Shoot(Vector2D position, float angleRad);

};

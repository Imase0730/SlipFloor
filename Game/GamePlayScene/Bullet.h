#pragma once

#include "Game/GameMath.h"

// 弾クラス
class Bullet
{
	// 列挙型の定義 -----------------------------------------------------
public:

	// クラス定数の宣言 -------------------------------------------------
public:

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

	// デストラクタ
	~Bullet();

	// 初期化関数
	void Initialize();

	// 更新関数
	void Update();

	// 描画関数
	void Render(int ghBullet);

	// 敵がアクティブか調べる関数
	bool IsActive() const { return m_isActive; }

	// 弾を発射する関数
	void Shoot(Vector2D position);

};

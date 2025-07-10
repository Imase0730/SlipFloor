#include "Bullet.h"
#include "Game/Screen.h"

// コンストラクタ
Bullet::Bullet()
	: m_isActive{ false }
	, m_position{ 0, 0 }
	, m_velocity{ 0, 0 }
{
}

// デストラクタ
Bullet::~Bullet()
{
}

// 初期化関数
void Bullet::Initialize()
{
}

// 更新関数
void Bullet::Update()
{
	// 位置に速度を足す
	m_position += m_velocity;
}

// 描画関数
void Bullet::Render(int ghBullet)
{
	// 画像を回転する事ができる関数
	DrawRotaGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y)
		, 1.0, 0.0, ghBullet, TRUE);
}

// 弾を発射する関数
void Bullet::Shoot(Vector2D position)
{
	// アクティブにする
	m_isActive = true;
}

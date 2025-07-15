#include "Bullet.h"
#include "Game/Screen.h"

// コンストラクタ
Bullet::Bullet()
	: m_isActive{ false }
	, m_position{ 0, 0 }
	, m_velocity{ 0, 0 }
{
}

// 更新関数
void Bullet::Update()
{
	// 位置に速度を足す
	m_position += m_velocity;

	// 画面外へ移動したら非アクティブにする
	if ( (m_position.x < -BULLET_SIZE)
	  || (m_position.x > Screen::GAME_WIDTH + BULLET_SIZE)
	  || (m_position.y < -BULLET_SIZE)
	  || (m_position.y > Screen::GAME_HEIGHT + BULLET_SIZE)
	   )
	{
		m_isActive = false;
	}
}

// 描画関数
void Bullet::Render(int ghBullet)
{
	// 画像を回転する事ができる関数
	DrawRotaGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y)
		, 1.0, 0.0, ghBullet, TRUE);
}

// 弾を発射する関数
void Bullet::Shoot(Vector2D position, float angleRad)
{
	// アクティブにする
	m_isActive = true;

	// 位置を設定する
	m_position = position;

	// 速度を設定する
	Vector2D v{ cosf(-angleRad), sinf(-angleRad) };
	m_velocity = v * MOVE_SPEED;
}

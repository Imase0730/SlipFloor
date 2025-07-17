#include "Enemy.h"
#include "Game/Screen.h"

Enemy::Enemy(Player* pPlayer)
	: m_position{ 0.0f, 0.0f }
	, m_angleRad{ 0.0f }
	, m_velocity{ 0.0f, 0.0f }
	, m_acceleration{ 0.0f, 0.0f }
	, m_pPlayer{ pPlayer }
{
}

void Enemy::Initialize()
{
	// 位置を初期化
	m_position = Vector2D{ Screen::GAME_WIDTH / 2.0f, Screen::GAME_HEIGHT / 2.0f - 200.0f};

	// 下向きにする
	m_angleRad = ToRadians(-90.0f);
}

void Enemy::Update(BulletManager& bulletManager)
{
	// ----- 外積をテストする ----- //

	//Vector2D v1{ 1.0f, 0.0f };
	//Vector2D v2{ 0.0f, 1.0f };

	//float a = Cross(v1, v2);
	//float b = Cross(v2, v1);

	// ---------------------------- //

	// 敵からプレイヤーへのベクトルを求める
	Vector2D v1 = m_pPlayer->GetPosition() - m_position;

	// 敵の向いている方向ベクトル
	Vector2D v2{ cosf(-m_angleRad), sinf(-m_angleRad) };

	// プレイヤーの方向へ向ける
	if (Cross(v1, v2) > 0.0f)
	{
		m_angleRad += ToRadians(4.0f);
	}
	else
	{
		m_angleRad -= ToRadians(4.0f);
	}

	// 速度に加速度を足す
	m_velocity += m_acceleration;

	// 速度を抑制する
	if (Length(m_velocity) > MOVE_SPEED_MAX)
	{
		// 速度を正規化（長さ１）して最大速度を掛ける
		m_velocity = Normalize(m_velocity) * MOVE_SPEED_MAX;
	}

	// 位置に速度を足す
	m_position += m_velocity;

	// 摩擦係数を掛けて速度を落とす
	m_velocity *= 0.99f;

	// 画面外に出ないようにする
	if (m_position.x < 0.0f) m_position.x = 0.0f;
	if (m_position.x > Screen::GAME_WIDTH) m_position.x = Screen::GAME_WIDTH;
	if (m_position.y < 0.0f) m_position.y = 0.0f;
	if (m_position.y > Screen::GAME_HEIGHT) m_position.y = Screen::GAME_HEIGHT;
}

void Enemy::Render(int ghEnemy)
{
	// 画像を回転する事ができる関数
	DrawRotaGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y)
		, 1.0, -m_angleRad, ghEnemy, TRUE);
}

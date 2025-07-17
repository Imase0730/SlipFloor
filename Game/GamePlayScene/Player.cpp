#include "Player.h"
#include "Game/Screen.h"

Player::Player()
	: m_position{ 0.0f, 0.0f }
	, m_angleRad{ 0.0f }
	, m_velocity{ 0.0f, 0.0f }
	, m_acceleration{ 0.0f, 0.0f }
{
}

void Player::Initialize()
{
	// 位置を初期化
	m_position = Vector2D{ Screen::GAME_WIDTH / 2.0f, Screen::GAME_HEIGHT / 2.0f + 200.0f};

	// 上に向ける
	m_angleRad = ToRadians(90.0f);
}

void Player::Update(int keyCondition, int keyTrigger, BulletManager& bulletManager)
{
	// 左キーが押された
	if (keyCondition & PAD_INPUT_LEFT)
	{
		m_angleRad += ToRadians(4.0f);
	}
	// 右キーが押された
	if (keyCondition & PAD_INPUT_RIGHT)
	{
		m_angleRad -= ToRadians(4.0f);
	}

	// 加速度をリセットする
	m_acceleration = Vector2D{ 0.0f, 0.0f };

	// 上キーが押されたら
	if (keyCondition & PAD_INPUT_UP)
	{
		Vector2D v{ cosf(-m_angleRad), sinf(-m_angleRad) };
		m_acceleration = v * MOVE_ACCELERATION;
	}

	// 下キーが押されたら
	if (keyCondition & PAD_INPUT_DOWN)
	{
		Vector2D v{ cosf(-m_angleRad), sinf(-m_angleRad) };
		m_acceleration = v * -MOVE_ACCELERATION;
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

	// スペースキーで弾を発射する
	if (keyTrigger & PAD_INPUT_10)
	{
		bulletManager.ShootBullet(m_position, m_angleRad);
	}
}

void Player::Render(int ghPlayer)
{
	// 画像を回転する事ができる関数
	DrawRotaGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y)
		, 1.0, -m_angleRad, ghPlayer, TRUE);
}

#include "Player.h"
#include "Game/Screen.h"

Player::Player()
	: m_position{ 0.0f, 0.0f }
	, m_angleRad{ 0.0f }
{
}

void Player::Initialize()
{
	// プレイヤーの位置を初期化
	m_position = Vector2D{ Screen::GAME_WIDTH / 2.0f, Screen::GAME_HEIGHT / 2.0f };
}

void Player::Update(int keyCondition, int keyTrigger)
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
}

void Player::Render(int ghPlayer)
{
	// 画像を回転する事ができる関数
	DrawRotaGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y)
		, 1.0, -m_angleRad, ghPlayer, TRUE);
}

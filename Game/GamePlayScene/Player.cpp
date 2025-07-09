#include "Player.h"
#include "Game/Screen.h"

Player::Player()
	: m_position{ 0.0f, 0.0f }
	, m_angleRad{ 0.0f }
{
}

void Player::Initialize()
{
	// �v���C���[�̈ʒu��������
	m_position = Vector2D{ Screen::GAME_WIDTH / 2.0f, Screen::GAME_HEIGHT / 2.0f };
}

void Player::Update(int keyCondition, int keyTrigger)
{
	// ���L�[�������ꂽ
	if (keyCondition & PAD_INPUT_LEFT)
	{
		m_angleRad += ToRadians(4.0f);
	}
	// �E�L�[�������ꂽ
	if (keyCondition & PAD_INPUT_RIGHT)
	{
		m_angleRad -= ToRadians(4.0f);
	}
}

void Player::Render(int ghPlayer)
{
	// �摜����]���鎖���ł���֐�
	DrawRotaGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y)
		, 1.0, -m_angleRad, ghPlayer, TRUE);
}

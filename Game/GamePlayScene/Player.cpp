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
	// �ʒu��������
	m_position = Vector2D{ Screen::GAME_WIDTH / 2.0f, Screen::GAME_HEIGHT / 2.0f + 200.0f};

	// ��Ɍ�����
	m_angleRad = ToRadians(90.0f);
}

void Player::Update(int keyCondition, int keyTrigger, BulletManager& bulletManager)
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

	// �����x�����Z�b�g����
	m_acceleration = Vector2D{ 0.0f, 0.0f };

	// ��L�[�������ꂽ��
	if (keyCondition & PAD_INPUT_UP)
	{
		Vector2D v{ cosf(-m_angleRad), sinf(-m_angleRad) };
		m_acceleration = v * MOVE_ACCELERATION;
	}

	// ���L�[�������ꂽ��
	if (keyCondition & PAD_INPUT_DOWN)
	{
		Vector2D v{ cosf(-m_angleRad), sinf(-m_angleRad) };
		m_acceleration = v * -MOVE_ACCELERATION;
	}

	// ���x�ɉ����x�𑫂�
	m_velocity += m_acceleration;

	// ���x��}������
	if (Length(m_velocity) > MOVE_SPEED_MAX)
	{
		// ���x�𐳋K���i�����P�j���čő呬�x���|����
		m_velocity = Normalize(m_velocity) * MOVE_SPEED_MAX;
	}

	// �ʒu�ɑ��x�𑫂�
	m_position += m_velocity;

	// ���C�W�����|���đ��x�𗎂Ƃ�
	m_velocity *= 0.99f;

	// ��ʊO�ɏo�Ȃ��悤�ɂ���
	if (m_position.x < 0.0f) m_position.x = 0.0f;
	if (m_position.x > Screen::GAME_WIDTH) m_position.x = Screen::GAME_WIDTH;
	if (m_position.y < 0.0f) m_position.y = 0.0f;
	if (m_position.y > Screen::GAME_HEIGHT) m_position.y = Screen::GAME_HEIGHT;

	// �X�y�[�X�L�[�Œe�𔭎˂���
	if (keyTrigger & PAD_INPUT_10)
	{
		bulletManager.ShootBullet(m_position, m_angleRad);
	}
}

void Player::Render(int ghPlayer)
{
	// �摜����]���鎖���ł���֐�
	DrawRotaGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y)
		, 1.0, -m_angleRad, ghPlayer, TRUE);
}

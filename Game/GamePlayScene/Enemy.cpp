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
	// �ʒu��������
	m_position = Vector2D{ Screen::GAME_WIDTH / 2.0f, Screen::GAME_HEIGHT / 2.0f - 200.0f};

	// �������ɂ���
	m_angleRad = ToRadians(-90.0f);
}

void Enemy::Update(BulletManager& bulletManager)
{
	// ----- �O�ς��e�X�g���� ----- //

	//Vector2D v1{ 1.0f, 0.0f };
	//Vector2D v2{ 0.0f, 1.0f };

	//float a = Cross(v1, v2);
	//float b = Cross(v2, v1);

	// ---------------------------- //

	// �G����v���C���[�ւ̃x�N�g�������߂�
	Vector2D v1 = m_pPlayer->GetPosition() - m_position;

	// �G�̌����Ă�������x�N�g��
	Vector2D v2{ cosf(-m_angleRad), sinf(-m_angleRad) };

	// �v���C���[�̕����֌�����
	if (Cross(v1, v2) > 0.0f)
	{
		m_angleRad += ToRadians(4.0f);
	}
	else
	{
		m_angleRad -= ToRadians(4.0f);
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
}

void Enemy::Render(int ghEnemy)
{
	// �摜����]���鎖���ł���֐�
	DrawRotaGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y)
		, 1.0, -m_angleRad, ghEnemy, TRUE);
}

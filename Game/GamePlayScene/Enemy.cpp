#include "Enemy.h"
#include "Game/Screen.h"

Enemy::Enemy(Player* pPlayer)
	: m_position{ 0.0f, 0.0f }
	, m_angleRad{ 0.0f }
	, m_velocity{ 0.0f, 0.0f }
	, m_acceleration{ 0.0f, 0.0f }
	, m_pPlayer{ pPlayer }
	, m_shootDelayFrame{ 0 }
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
	// �G����v���C���[�ւ̃x�N�g�������߂�
	Vector2D v1 = m_pPlayer->GetPosition() - m_position;

	// �G�ƃv���C���[�̋��������߂�
	float distance = Length(v1);

	// v1�x�N�g���𐳋K������
	v1 = Normalize(v1);

	// �G�̌����Ă�������x�N�g��
	Vector2D v2{ cosf(-m_angleRad), sinf(-m_angleRad) };

	// �G�ƃv���C���[�̂Ȃ��p�x�����߂�
	float angle = ToDegrees(acosf(Dot(v1, v2)));

	// �v���C���[�̕����֌�����
	if (Cross(v2, v1) > 0.0f)
	{
		m_angleRad -= ToRadians(TURN_ANGLE);
	}
	else
	{
		m_angleRad += ToRadians(TURN_ANGLE);
	}

	m_acceleration = Vector2D{ 0.0f, 0.0f };
	if ( (angle < (VIEW_ANGLE / 2.0f))		// ����ɓ����Ă���
	  && (distance > APPROACH_DISTANCE)		// �߂Â������Ȃ�
	   )
	{
		// �v���C���[�ɋ߂Â�
		Vector2D v{ cosf(-m_angleRad), sinf(-m_angleRad) };
		m_acceleration = v * MOVE_ACCELERATION;
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

	// �e�𔭎˂���
	m_shootDelayFrame++;
	if ( (m_shootDelayFrame > SHOOT_INTERVAL_FRAME)	// ���̊Ԋu��
	  && (distance < SHOOT_DISTANCE)				// �߂Â���
	  && (angle < (SHOOT_VIEW_ANGLE / 2.0f))		// ����p�ɓ�������
	   )
	{
		m_shootDelayFrame = 0;
		bulletManager.ShootBullet(m_position, m_angleRad);
	}

}

void Enemy::Render(int ghEnemy)
{
	// �摜����]���鎖���ł���֐�
	DrawRotaGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y)
		, 1.0, -m_angleRad, ghEnemy, TRUE);
}

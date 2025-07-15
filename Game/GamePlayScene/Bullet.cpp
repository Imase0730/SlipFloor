#include "Bullet.h"
#include "Game/Screen.h"

// �R���X�g���N�^
Bullet::Bullet()
	: m_isActive{ false }
	, m_position{ 0, 0 }
	, m_velocity{ 0, 0 }
{
}

// �X�V�֐�
void Bullet::Update()
{
	// �ʒu�ɑ��x�𑫂�
	m_position += m_velocity;

	// ��ʊO�ֈړ��������A�N�e�B�u�ɂ���
	if ( (m_position.x < -BULLET_SIZE)
	  || (m_position.x > Screen::GAME_WIDTH + BULLET_SIZE)
	  || (m_position.y < -BULLET_SIZE)
	  || (m_position.y > Screen::GAME_HEIGHT + BULLET_SIZE)
	   )
	{
		m_isActive = false;
	}
}

// �`��֐�
void Bullet::Render(int ghBullet)
{
	// �摜����]���鎖���ł���֐�
	DrawRotaGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y)
		, 1.0, 0.0, ghBullet, TRUE);
}

// �e�𔭎˂���֐�
void Bullet::Shoot(Vector2D position, float angleRad)
{
	// �A�N�e�B�u�ɂ���
	m_isActive = true;

	// �ʒu��ݒ肷��
	m_position = position;

	// ���x��ݒ肷��
	Vector2D v{ cosf(-angleRad), sinf(-angleRad) };
	m_velocity = v * MOVE_SPEED;
}

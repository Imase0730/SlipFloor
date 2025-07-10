#include "Bullet.h"
#include "Game/Screen.h"

// �R���X�g���N�^
Bullet::Bullet()
	: m_isActive{ false }
	, m_position{ 0, 0 }
	, m_velocity{ 0, 0 }
{
}

// �f�X�g���N�^
Bullet::~Bullet()
{
}

// �������֐�
void Bullet::Initialize()
{
}

// �X�V�֐�
void Bullet::Update()
{
	// �ʒu�ɑ��x�𑫂�
	m_position += m_velocity;
}

// �`��֐�
void Bullet::Render(int ghBullet)
{
	// �摜����]���鎖���ł���֐�
	DrawRotaGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y)
		, 1.0, 0.0, ghBullet, TRUE);
}

// �e�𔭎˂���֐�
void Bullet::Shoot(Vector2D position)
{
	// �A�N�e�B�u�ɂ���
	m_isActive = true;
}

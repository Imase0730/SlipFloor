#pragma once

#include "Game/GameMath.h"
#include "BulletManager.h"
#include "Player.h"

// �G�N���X
class Enemy
{
	// �萔�錾 -----------------------------------------
private:

	// �ő�ړ����x
	static constexpr float MOVE_SPEED_MAX = 4.0f;

	// �ړ����̉����x
	static constexpr float MOVE_ACCELERATION = 0.1f;

	// �����o�ϐ� ---------------------------------------
private:

	// �ʒu
	Vector2D m_position;

	// ����
	float m_angleRad;

	// ���x
	Vector2D m_velocity;

	// �����x
	Vector2D m_acceleration;

	// �v���C���[�ւ̃|�C���^
	Player* m_pPlayer;

	// �����o�֐� ---------------------------------------
public:

	// �R���X�g���N�^
	Enemy(Player* pPlayer);

	// �������֐�
	void Initialize();

	// �X�V����
	void Update(BulletManager& bulletManager);

	// �`�揈��
	void Render(int ghEnemy);

};

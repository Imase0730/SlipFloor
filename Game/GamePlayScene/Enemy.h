#pragma once

#include "Game/GameMath.h"
#include "BulletManager.h"
#include "Player.h"
#include "Game/Collision.h"

// �G�N���X
class Enemy
{
	// �萔�錾 -----------------------------------------
private:

	// ���a
	static constexpr float RADIUS = 16.0f;

	// �ő�ړ����x
	static constexpr float MOVE_SPEED_MAX = 4.0f;

	// �ړ����̉����x
	static constexpr float MOVE_ACCELERATION = 0.1f;

	// �v���C���[�ɋ߂Â�����
	static constexpr float APPROACH_DISTANCE = 100.0f;

	// ��]�p�x
	static constexpr float TURN_ANGLE = 2.0f;

	// �G�̎���p
	static constexpr float VIEW_ANGLE = 60.0f;

	// �e�̔��ˊԊu
	static constexpr int SHOOT_INTERVAL_FRAME = 60;

	// �e�𔭎˂��鋗��
	static constexpr float SHOOT_DISTANCE = 300.0f;

	// �e�𔭎˂��鎋��p
	static constexpr float SHOOT_VIEW_ANGLE = 20.0f;

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

	// �e�𔭎˂���Ԋu�̃t���[����
	int m_shootDelayFrame;

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

	// �ʒu��ݒ肷��֐�
	void SetPosition(Vector2D position) { m_position = position; }

	// �Փ˔���p�̉~�����擾����֐�
	BoundingCircle GetBoundingCircle() { return BoundingCircle{ m_position, RADIUS }; }

};

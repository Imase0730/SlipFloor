#pragma once

#include "Game/GameMath.h"
#include "BulletManager.h"
#include "Game/Collision.h"

// �v���C���[�N���X
class Player
{
	// �萔�錾 -----------------------------------------
private:

	// ���a
	static constexpr float RADIUS = 16.0f;

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

	// �����o�֐� ---------------------------------------
public:

	// �R���X�g���N�^
	Player();

	// �������֐�
	void Initialize();

	// �X�V����
	void Update(int keyCondition, int keyTrigger, BulletManager& bulletManager);

	// �`�揈��
	void Render(int ghPlayer);

	// �ʒu���擾����֐�
	Vector2D GetPosition() const { return m_position; }

	// �ʒu��ݒ肷��֐�
	void SetPosition(Vector2D position) { m_position = position; }

	// �Փ˔���p�̉~�����擾����֐�
	BoundingCircle GetBoundingCircle() { return BoundingCircle{ m_position, RADIUS }; }

};

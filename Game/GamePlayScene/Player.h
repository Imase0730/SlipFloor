#pragma once

#include "Game/GameMath.h"

// �v���C���[�N���X
class Player
{
	// �萔�錾 -----------------------------------------
private:

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
	void Update(int keyCondition, int keyTrigger);

	// �`�揈��
	void Render(int ghPlayer);

};

#pragma once

#include "Game/GameMath.h"

// �v���C���[�N���X
class Player
{
	// �����o�ϐ� ---------------------------------------
private:

	// �ʒu
	Vector2D m_position;

	// ����
	float m_angleRad;

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

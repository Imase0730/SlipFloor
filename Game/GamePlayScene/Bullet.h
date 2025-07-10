#pragma once

#include "Game/GameMath.h"

// �e�N���X
class Bullet
{
	// �񋓌^�̒�` -----------------------------------------------------
public:

	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �A�N�e�B�u�Ȃ�true��ݒ�
	bool m_isActive;

	// �ʒu
	Vector2D m_position;

	// ���x
	Vector2D m_velocity;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	Bullet();

	// �f�X�g���N�^
	~Bullet();

	// �������֐�
	void Initialize();

	// �X�V�֐�
	void Update();

	// �`��֐�
	void Render(int ghBullet);

	// �G���A�N�e�B�u�����ׂ�֐�
	bool IsActive() const { return m_isActive; }

	// �e�𔭎˂���֐�
	void Shoot(Vector2D position);

};

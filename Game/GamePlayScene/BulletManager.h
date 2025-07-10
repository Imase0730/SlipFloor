#pragma once

#include "Bullet.h"

// �e�̃}�l�[�W���[�N���X
class BulletManager
{
	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �Ǘ��ł���e�̐�
	int m_bulletCount;

	// �e�̃I�u�W�F�N�g�ւ̃|�C���^
	Bullet* m_pBullet;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	BulletManager();

	// �f�X�g���N�^
	~BulletManager();

	// ����������
	void Initialize(Bullet::Type type, int BulletCount);

	// �X�V����
	void Update();

	// �`�揈��
	void Render(int ghShootingGame);

	// �I������
	void Finalize();

	// �e�𔭎˂���֐�
	void ShootBullet(POINT point);

	// �Ǘ����Ă���e���擾����֐�
	Bullet* GetBullet(int index);

	// �Ǘ����Ă���e�̐����擾����֐�
	int GetBulletCount() const { return m_bulletCount; }

};

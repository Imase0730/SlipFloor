#include "BulletManager.h"
#include "Game/Screen.h"

// �R���X�g���N�^
BulletManager::BulletManager()
	: m_bulletCount{ 0 }
	, m_pBullet{ nullptr }
{
}

// �f�X�g���N�^
BulletManager::~BulletManager()
{
	// �m�ۂ������������������
	if (m_pBullet) delete[] m_pBullet;
}

// ����������
void BulletManager::Initialize(Bullet::Type type, int bulletCount)
{
	// �Ǘ�����e�̐�
	m_bulletCount = bulletCount;

	// ������x���������m�ۂ���Ă�����������
	if (m_pBullet) delete[] m_pBullet;

	// �e�̐������������m�ۂ���
	m_pBullet = new Bullet[bulletCount];

	// �e�̃^�C�v��ݒ肷��
	for (int i = 0; i < bulletCount; i++)
	{
		m_pBullet[i].SetType(type);
	}
}

// �X�V����
void BulletManager::Update()
{
	// �S�Ă̒e�̍X�V�������s��
	for (int i = 0; i < m_bulletCount; i++)
	{
		// �e���A�N�e�B�u��������X�V����
		if (m_pBullet[i].IsActive()) m_pBullet[i].Update();
	}
}

// �`�揈��
void BulletManager::Render(int ghShootingGame)
{
	// �S�Ă̒e�̕`�揈�����s��
	for (int i = 0; i < m_bulletCount; i++)
	{
		// �e���A�N�e�B�u��������`�悷��
		if (m_pBullet[i].IsActive()) m_pBullet[i].Render(ghShootingGame);
	}
}

// �I������
void BulletManager::Finalize()
{
}

// �e�𔭎˂���֐�
void BulletManager::ShootBullet(POINT position)
{
	for (int i = 0; i < m_bulletCount; i++)
	{
		// �e�����g�p��������
		if (!m_pBullet[i].IsActive())
		{
			// �e�𔭎˂���
			m_pBullet[i].Shoot(position);
			return;
		}
	}
}

// �Ǘ����Ă���e���擾����֐�
Bullet* BulletManager::GetBullet(int index)
{
	// �e�̔z��̓Y�����ɂł���C���f�b�N�X���`�F�b�N����
	if ((index < 0) || (index >= m_bulletCount)) return nullptr;

	// �e�̃��[�N���g�p���Ȃ�
	if (m_pBullet[index].IsActive())
	{
		return &m_pBullet[index];
	}

	return nullptr;
}


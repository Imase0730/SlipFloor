//--------------------------------------------------------------------------------------
// File: GamePlayScene.cpp
//
//--------------------------------------------------------------------------------------
#include "GamePlayScene.h"
#include "Game/Game.h"
#include "Game/Screen.h"
#include "Game/Collision.h"

// �R���X�g���N�^
GamePlayScene::GamePlayScene(Game* pGame)
	: m_pGame{ pGame }
	, m_ghPlayer{ -1 }
	, m_ghEnemy{ -1 }
	, m_ghBullet{ -1 }
	, m_player{}
	, m_playerBulletManager{}
	, m_enemy{ &m_player }
	, m_enemyBulletManager{}
{
}

// �f�X�g���N�^
GamePlayScene::~GamePlayScene()
{
}

// ����������
void GamePlayScene::Initialize()
{
	// �G�̓ǂݍ���
	m_ghPlayer = LoadGraph(L"Resources/Textures/Player.png");
	m_ghEnemy = LoadGraph(L"Resources/Textures/Enemy.png");
	m_ghBullet = LoadGraph(L"Resources/Textures/Bullet.png");

	// �v���C���[�̏�����
	m_player.Initialize();

	// �v���C���[�̒e�̃}�l�[�W���[�̏�����
	m_playerBulletManager.Initialize(10);

	// �G�̏�����
	m_enemy.Initialize();

	// �G�̒e�̃}�l�[�W���[�̏�����
	m_enemyBulletManager.Initialize(10);

}

// �X�V����
void GamePlayScene::Update(int keyCondition, int keyTrigger)
{
	// �v���C���[�̍X�V
	m_player.Update(keyCondition, keyTrigger, m_playerBulletManager);

	// �v���C���[�̒e�̃}�l�[�W���[�̍X�V
	m_playerBulletManager.Update();

	// �G�̍X�V
	m_enemy.Update(m_enemyBulletManager);

	// �G�̒e�̃}�l�[�W���[�̍X�V
	m_enemyBulletManager.Update();

	// �v���C���[�ƓG�̏Փ˔���
	if (IsCircleColliding(m_player.GetBoundingCircle(), m_enemy.GetBoundingCircle()))
	{
		// �d�Ȃ�Ȃ��悤�Ɉʒu���C������
		BoundingCircle player = m_player.GetBoundingCircle();
		BoundingCircle enemy = m_enemy.GetBoundingCircle();
		ResolveOverlap(&player, &enemy);
		m_player.SetPosition(player.center);
		m_enemy.SetPosition(enemy.center);
	}
}

// �`�揈��
void GamePlayScene::Render()
{
	// �v���C���[�̕`��
	m_player.Render(m_ghPlayer);

	// �G�̕`��
	m_enemy.Render(m_ghEnemy);

	// �v���C���[�̒e�̃}�l�[�W���[�̕`��
	m_playerBulletManager.Render(m_ghBullet);

	// �G�̒e�̃}�l�[�W���[�̕`��
	m_enemyBulletManager.Render(m_ghBullet);

	DrawFormatString(10, 30, GetColor(255, 255, 255), L"GamePlay�V�[��");
}
 
// �I������
void GamePlayScene::Finalize()
{
	// �ǂݍ��񂾊G�̉��
	DeleteGraph(m_ghPlayer);
	DeleteGraph(m_ghEnemy);
	DeleteGraph(m_ghBullet);
}


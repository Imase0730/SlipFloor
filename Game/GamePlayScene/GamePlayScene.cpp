//--------------------------------------------------------------------------------------
// File: GamePlayScene.cpp
//
//--------------------------------------------------------------------------------------
#include "GamePlayScene.h"
#include "Game/Game.h"
#include "Game/Screen.h"

// �R���X�g���N�^
GamePlayScene::GamePlayScene(Game* pGame)
	: m_pGame{ pGame }
	, m_ghPlayer{ -1 }
	, m_ghBullet{ -1 }
	, m_player{}
	, m_bullet{}
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
	m_ghBullet = LoadGraph(L"Resources/Textures/Bullet.png");

	// �v���C���[�̏�����
	m_player.Initialize();
}

// �X�V����
void GamePlayScene::Update(int keyCondition, int keyTrigger)
{
	// �v���C���[�̍X�V
	m_player.Update(keyCondition, keyTrigger);
}

// �`�揈��
void GamePlayScene::Render()
{
	// �v���C���[�̕`��
	m_player.Render(m_ghPlayer);

	// �e�̕`��
	m_bullet.Render(m_ghBullet);

	DrawFormatString(10, 30, GetColor(255, 255, 255), L"GamePlay�V�[��");
}
 
// �I������
void GamePlayScene::Finalize()
{
	// �ǂݍ��񂾊G�̉��
	DeleteGraph(m_ghPlayer);
	DeleteGraph(m_ghBullet);
}


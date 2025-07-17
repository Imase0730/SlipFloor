//--------------------------------------------------------------------------------------
// File: GamePlayScene.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Player.h"
#include "Enemy.h"
#include "BulletManager.h"

// �N���X�̑O���錾
class Game;

// �^�C�g���V�[��
class GamePlayScene
{
	// �񋓌^�̒�` -----------------------------------------------------
private:


	// �N���X�萔�̐錾 -------------------------------------------------
public:


	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// ���̃V�[�����܂ރQ�[���I�u�W�F�N�g�ւ̃|�C���^
	Game* m_pGame;

	// �v���C���[�̊G�̃O���t�B�b�N�n���h��
	int m_ghPlayer;

	// �G�̊G�̃O���t�B�b�N�n���h��
	int m_ghEnemy;

	// �e�̊G�̃O���t�B�b�N�n���h��
	int m_ghBullet;

	// �v���C���[
	Player m_player;

	// �v���C���[�̒e�̃}�l�[�W���[
	BulletManager m_playerBulletManager;

	// �G
	Enemy m_enemy;

	// �G�̒e�̃}�l�[�W���[
	BulletManager m_enemyBulletManager;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	GamePlayScene(Game* pGame);

	// �f�X�g���N�^
	~GamePlayScene();

	// ����������
	void Initialize();

	// �X�V����
	void Update(int keyCondition, int keyTrigger);

	// �`�揈��
	void Render();

	// �I������
	void Finalize();

};

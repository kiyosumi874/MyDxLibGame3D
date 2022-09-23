//-----------------------------------------------------------------------------
// @brief  �v���C�V�[���N���X.
// 2022 Kiyosumi Shiihara All Rights Reserved.
//-----------------------------------------------------------------------------

#include "PlayScene.h"
#include "DxLib.h"
#include "Player.h"
#include "Camera.h"
#include "ObstructManager.h"
#include "HitChecker.h"
#include "Utility.h"

//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.
//-----------------------------------------------------------------------------
PlayScene::PlayScene()
	: Scene(SceneType::PLAY)
{
	// �J�����̐���
	camera = new Camera;
	// �v���C���[�̐���
	player = new Player;
	// �I�u�X�g���N�g�}�l�[�W���[�̐���
	obstructManager = new ObstructManager;
	obstructManager->CreateObstructs();
}

//-----------------------------------------------------------------------------
// @brief  �f�X�g���N�^.
//-----------------------------------------------------------------------------
PlayScene::~PlayScene()
{
	// �J���������.
	SAFE_DELETE(camera);

	// �v���C���[�����.
	SAFE_DELETE(player);

	// ��Q�������.
	obstructManager->DestroyObstructs();
	SAFE_DELETE(obstructManager);

}

//-----------------------------------------------------------------------------
// @brief  �X�V.
//-----------------------------------------------------------------------------
SceneType PlayScene::Update()
{
	// ���̃V�[����
	if (CheckHitKey(KEY_INPUT_X))
	{
		nowSceneType = SceneType::RESULT;
	}

	// �v���C���[����.
	player->Update();

	// �J��������.
	camera->Update(*player);

	// ��Q������.
	obstructManager->Update();

	// �q�b�g�̃`�F�b�N.
	HitChecker::Check(*player, *obstructManager);

	return nowSceneType;
}

//-----------------------------------------------------------------------------
// @brief  �`��.
//-----------------------------------------------------------------------------
void PlayScene::Draw()
{
#ifdef _DEBUG
	printfDx("PlayScene\nPress:X -> ResultScene\n");
#endif // _DEBUG

	// �v���C���[�`��.
	player->Draw();

	// ��Q���`��.
	obstructManager->Draw();

}

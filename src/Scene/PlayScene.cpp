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
#include "Macro.h"

//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.
//-----------------------------------------------------------------------------
PlayScene::PlayScene()
	: Scene(SceneType::PLAY)
{
	pCamera = new Camera;
	pPlayer = new Player;
	pObstructManager = new ObstructManager;
	pObstructManager->CreateObstructs();
}

//-----------------------------------------------------------------------------
// @brief  �f�X�g���N�^.
//-----------------------------------------------------------------------------
PlayScene::~PlayScene()
{
	// �J�������폜.
	SAFE_DELETE(pCamera);

	// �v���C���[���폜.
	SAFE_DELETE(pPlayer);

	// ��Q�����폜.
	pObstructManager->DestroyObstructs();
	SAFE_DELETE(pObstructManager);

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
	pPlayer->Update();

	// �J��������.
	pCamera->Update(*pPlayer);

	// ��Q������.
	pObstructManager->Update();

	// �q�b�g�̃`�F�b�N.
	HitChecker::Check(*pPlayer, *pObstructManager);

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
	pPlayer->Draw();

	// ��Q���`��.
	pObstructManager->Draw();

}

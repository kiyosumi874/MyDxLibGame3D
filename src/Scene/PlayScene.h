//-----------------------------------------------------------------------------
// @brief  �v���C�V�[���N���X.
// 2022 Kiyosumi Shiihara All Rights Reserved.
//-----------------------------------------------------------------------------
#pragma once
#include "Scene.h"

// �O���錾
class Camera;
class Player;
class ObstructManager;

// final�w��q������Ƃ���ȏ�N���X��h���ł��Ȃ��Ȃ�.
class PlayScene final : public Scene
{
public:
	PlayScene();                // �R���X�g���N�^.
	~PlayScene()      override; // �f�X�g���N�^.

	SceneType Update() override; // �X�V.
	void Draw()        override; // �`��.

private:
	Camera* pCamera;
	Player* pPlayer;
	ObstructManager* pObstructManager;
};
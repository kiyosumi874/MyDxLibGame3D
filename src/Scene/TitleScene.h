//-----------------------------------------------------------------------------
// @brief  �^�C�g���V�[���N���X.
// 2022 Kiyosumi Shiihara All Rights Reserved.
//-----------------------------------------------------------------------------

#pragma once
#include "Scene.h"

// final�w��q������Ƃ���ȏ�N���X��h���ł��Ȃ��Ȃ�.
class TitleScene final : public Scene
{
public:
	TitleScene();                // �R���X�g���N�^.
	~TitleScene()      override; // �f�X�g���N�^.

	SceneType Update() override; // �X�V.
	void Draw()        override; // �`��.

private:

};
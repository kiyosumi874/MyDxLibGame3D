﻿//-----------------------------------------------------------------------------
// @brief  タイトルシーンクラス.
// 2022 Kiyosumi Shiihara All Rights Reserved.
//-----------------------------------------------------------------------------

#include "TitleScene.h"
#include "DxLib.h"

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
TitleScene::TitleScene()
	: Scene(SceneType::TITLE)
{
	// 処理無し
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
TitleScene::~TitleScene()
{
	// 処理無し
}

//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
SceneType TitleScene::Update()
{
	// 次のシーンへ.
	if (CheckHitKey(KEY_INPUT_Z))
	{
		nowSceneType = SceneType::PLAY;
	}
	return nowSceneType;
}

//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void TitleScene::Draw()
{
#ifdef _DEBUG
	printfDx("TitleScene\nPress:Z -> PlayScene\n");
#endif // _DEBUG
}

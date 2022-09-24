//-----------------------------------------------------------------------------
// @brief  タイトルシーンクラス.
// 2022 Kiyosumi Shiihara All Rights Reserved.
//-----------------------------------------------------------------------------

#pragma once
#include "Scene.h"

// final指定子をつけるとこれ以上クラスを派生できなくなる.
class TitleScene final : public Scene
{
public:
	TitleScene();                // コンストラクタ.
	~TitleScene()      override; // デストラクタ.

	SceneType Update() override; // 更新.
	void Draw()        override; // 描画.
};
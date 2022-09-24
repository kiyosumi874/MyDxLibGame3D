//-----------------------------------------------------------------------------
// @brief  リザルトシーンクラス.
// 2022 Kiyosumi Shiihara All Rights Reserved.
//-----------------------------------------------------------------------------

#pragma once
#include "Scene.h"

// final指定子をつけるとこれ以上クラスを派生できなくなる.
class ResultScene final : public Scene
{
public:
	ResultScene();                // コンストラクタ.
	~ResultScene()      override; // デストラクタ.

	SceneType Update() override; // 更新.
	void Draw()        override; // 描画.
};
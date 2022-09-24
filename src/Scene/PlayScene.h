//-----------------------------------------------------------------------------
// @brief  プレイシーンクラス.
// 2022 Kiyosumi Shiihara All Rights Reserved.
//-----------------------------------------------------------------------------
#pragma once
#include "Scene.h"

// final指定子をつけるとこれ以上クラスを派生できなくなる.
class PlayScene final : public Scene
{
public:
	PlayScene();                // コンストラクタ.
	~PlayScene()      override; // デストラクタ.

	SceneType Update() override; // 更新.
	void Draw()        override; // 描画.

private:
	// classは前方宣言の代わり.
	// 前方宣言が分からない人は調べてみよう.
	class Camera* camera;
	class Player* player;
	class ObstructManager* obstructManager;
};
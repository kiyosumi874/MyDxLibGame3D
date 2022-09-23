//-----------------------------------------------------------------------------
// @brief  プレイシーンクラス.
// 2022 Kiyosumi Shiihara All Rights Reserved.
//-----------------------------------------------------------------------------
#pragma once
#include "Scene.h"

// 前方宣言
class Camera;
class Player;
class ObstructManager;

// final指定子をつけるとこれ以上クラスを派生できなくなる.
class PlayScene final : public Scene
{
public:
	PlayScene();                // コンストラクタ.
	~PlayScene()      override; // デストラクタ.

	SceneType Update() override; // 更新.
	void Draw()        override; // 描画.

private:
	Camera* pCamera;
	Player* pPlayer;
	ObstructManager* pObstructManager;
};
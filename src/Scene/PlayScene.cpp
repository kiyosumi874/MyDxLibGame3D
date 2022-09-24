//-----------------------------------------------------------------------------
// @brief  プレイシーンクラス.
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
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
PlayScene::PlayScene()
	: Scene(SceneType::PLAY)
	, camera(new Camera())
	, player(new Player())
	, obstructManager(new ObstructManager())
{
	// 障害物の生成.
	obstructManager->CreateObstructs();
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
PlayScene::~PlayScene()
{
	// カメラを解放.
	SAFE_DELETE(camera);

	// プレイヤーを解放.
	SAFE_DELETE(player);

	// 障害物を解放.
	obstructManager->DestroyObstructs();
	SAFE_DELETE(obstructManager);
}

//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
SceneType PlayScene::Update()
{
	// プレイヤー制御.
	player->Update();

	// カメラ制御.
	camera->Update(*player);

	// 障害物制御.
	obstructManager->Update();

	// 当たり判定.
	HitChecker::Check(*player, *obstructManager);

	// 次のシーンへ.
	if (CheckHitKey(KEY_INPUT_X))
	{
		nowSceneType = SceneType::RESULT;
	}

	return nowSceneType;
}

//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void PlayScene::Draw()
{
#ifdef _DEBUG
	printfDx("PlayScene\nPress:X -> ResultScene\n");
#endif // _DEBUG

	// プレイヤー描画.
	player->Draw();

	// 障害物描画.
	obstructManager->Draw();
}

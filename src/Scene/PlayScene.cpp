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
#include "Macro.h"

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
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
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
PlayScene::~PlayScene()
{
	// カメラを削除.
	SAFE_DELETE(pCamera);

	// プレイヤーを削除.
	SAFE_DELETE(pPlayer);

	// 障害物を削除.
	pObstructManager->DestroyObstructs();
	SAFE_DELETE(pObstructManager);

}

//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
SceneType PlayScene::Update()
{
	// 次のシーンへ
	if (CheckHitKey(KEY_INPUT_X))
	{
		nowSceneType = SceneType::RESULT;
	}

	// プレイヤー制御.
	pPlayer->Update();

	// カメラ制御.
	pCamera->Update(*pPlayer);

	// 障害物制御.
	pObstructManager->Update();

	// ヒットのチェック.
	HitChecker::Check(*pPlayer, *pObstructManager);

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
	pPlayer->Draw();

	// 障害物描画.
	pObstructManager->Draw();

}

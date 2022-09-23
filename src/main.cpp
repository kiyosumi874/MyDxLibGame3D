//-----------------------------------------------------------------------------
// @brief  メイン処理.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "DxLib.h"
#include "Scene.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "ResultScene.h"
#include "Macro.h"

// 関数プロトタイプ宣言.
void SceneChanger(Scene*& pScene, SceneType now, SceneType prev);

//-----------------------------------------------------------------------------
// @brief  メイン関数.
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) 
{
	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)		
	{
		return -1;	// エラーが起きたら直ちに終了
	}

	// 画面モードのセット
	SetGraphMode(640, 480, 16);
	ChangeWindowMode(TRUE);

	// ひとつ前のシーン.
	SceneType prevSceneType = SceneType::TITLE;
	// 今のシーン.
	SceneType nowSceneType = SceneType::TITLE;

	// シーンを生成.
	Scene* pScene = new TitleScene;
	
	// エスケープキーが押されるかウインドウが閉じられるまでループ.
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// ↓今のシーンを記録.
		nowSceneType = pScene->Update(); // 更新.
		
#ifdef _DEBUG
		clsDx(); // printfDx の結果をリセットするための関数.
#endif // _DEBUG
		ClearDrawScreen(); // 画面を初期化する.
		pScene->Draw();  // 描画.
		ScreenFlip();      // 裏画面の内容を表画面に反映させる.

		SceneChanger(pScene, nowSceneType, prevSceneType); // シーンの切り替え.

		if (pScene == nullptr) { break; } // nowSceneの中に何もなかったら終了.

		// ひとつ前のシーンを記録.
		prevSceneType = nowSceneType;
	}

	SAFE_DELETE(pScene);

	// ＤＸライブラリの後始末.
	DxLib_End();

	// ソフトの終了.
	return 0;
}

// 今のシーンと前のシーンが異なる場合.
// 新しいシーンを生成する.
//                     ↓これはポインタ型を参照している(これをしないと関数外のpSceneが書き換わらない)
void SceneChanger(Scene*& pScene, SceneType now, SceneType prev)
{
	if (now != prev)
	{
		SAFE_DELETE(pScene);
		switch (now)
		{
		case SceneType::TITLE:
			pScene = new TitleScene;
			break;
		case SceneType::PLAY:
			pScene = new PlayScene;
			break;
		case SceneType::RESULT:
			pScene = new ResultScene;
			break;
		default:
			break;
		}
	}
}

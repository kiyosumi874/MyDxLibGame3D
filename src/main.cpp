//-----------------------------------------------------------------------------
// @brief  メイン処理.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "DxLib.h"
#include "Scene.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "ResultScene.h"
#include "Utility.h"

// 関数プロトタイプ宣言.
// シーンの切り替え.
void SceneChanger(Scene*& scene, SceneType now, SceneType prev);

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
	Scene* scene = new TitleScene;
	
	// エスケープキーが押されるかウインドウが閉じられるまでループ.
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// ↓今のシーンを記録.
		nowSceneType = scene->Update(); // 更新.
		
#ifdef _DEBUG
		clsDx(); // printfDx の結果をリセットするための関数.
#endif // _DEBUG
		ClearDrawScreen(); // 画面を初期化する.
		scene->Draw();  // 描画.
		ScreenFlip();      // 裏画面の内容を表画面に反映させる.

		SceneChanger(scene, nowSceneType, prevSceneType); // シーンの切り替え.

		if (scene == nullptr) { break; } // nowSceneの中に何もなかったら終了.

		// ひとつ前のシーンを記録.
		prevSceneType = nowSceneType;
	}

	// シーンの解放
	SAFE_DELETE(scene);

	// ＤＸライブラリの後始末.
	DxLib_End();

	// ソフトの終了.
	return 0;
}

// 今のシーンと前のシーンが異なる場合.
// 新しいシーンを生成する.
//                     ↓これはポインタ型を参照している(これをしないと関数外のpSceneが書き換わらない)
void SceneChanger(Scene*& scene, SceneType now, SceneType prev)
{
	if (now != prev)
	{
		SAFE_DELETE(scene);
		switch (now)
		{
		case SceneType::TITLE:
			scene = new TitleScene;
			break;
		case SceneType::PLAY:
			scene = new PlayScene;
			break;
		case SceneType::RESULT:
			scene = new ResultScene;
			break;
		default:
			break;
		}
	}
}

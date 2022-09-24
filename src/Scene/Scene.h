//-----------------------------------------------------------------------------
// @brief  シーン基底クラス.
// 2022 Kiyosumi Shiihara All Rights Reserved.
//-----------------------------------------------------------------------------

#pragma once

// シーンの種類.
enum class SceneType
{
	TITLE,
	PLAY,
	RESULT
};

class Scene
{
public:
	Scene(SceneType sceneType):nowSceneType(sceneType){ /*処理無し*/ } // コンストラクタ.
	virtual ~Scene() { /*処理無し*/ } // デストラクタ.

	virtual SceneType Update() = 0; // 更新.
	virtual void Draw() = 0; // 描画.
protected:
	SceneType nowSceneType; // 今のSceneType
};
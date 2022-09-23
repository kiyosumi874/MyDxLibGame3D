//-----------------------------------------------------------------------------
// @brief  シーン基底クラス.
// 2022 Kiyosumi Shiihara All Rights Reserved.
//-----------------------------------------------------------------------------

#pragma once

// シーンの種類(main.cppのswitch文などで使用).
enum class SceneType
{
	TITLE,
	PLAY,
	RESULT
};

class Scene
{
public:
	Scene(SceneType sceneType) { nowSceneType = sceneType; }
	
	virtual ~Scene() { /*処理無し*/ }

	virtual SceneType Update() = 0;
	virtual void Draw() = 0;
protected:
	SceneType nowSceneType;
};
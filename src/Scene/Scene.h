//-----------------------------------------------------------------------------
// @brief  �V�[�����N���X.
// 2022 Kiyosumi Shiihara All Rights Reserved.
//-----------------------------------------------------------------------------

#pragma once

// �V�[���̎��(main.cpp��switch���ȂǂŎg�p).
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
	
	virtual ~Scene() { /*��������*/ }

	virtual SceneType Update() = 0;
	virtual void Draw() = 0;
protected:
	SceneType nowSceneType;
};
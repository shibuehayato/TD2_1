#pragma once
#include "Audio.h"
#include "DebugCamera.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Player.h"
#include "Road.h"
#include "SafeDelete.h"
#include "Scene.h"
#include "Sprite.h"
#include "Stage.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

class ClearScene {
public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	ClearScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~ClearScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	bool isSceneEnd = false;
	bool IsSceneEnd() { return isSceneEnd; }

	SceneType NextScene() { return SceneType::kTitle; }

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	uint32_t textureHandle_ = 0;
	Model* model_ = nullptr;

	ViewProjection viewProjection_;

	bool isDebugCameraActive_ = false;

	DebugCamera* debugCamera_ = nullptr;

	Sprite* clear_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
	/// 
	



};

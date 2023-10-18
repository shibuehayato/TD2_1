﻿#pragma once
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

class TitleScene {
public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	TitleScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~TitleScene();

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


	SceneType NextScene() {
			return SceneType::kGamePlay;
	}

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	uint32_t textureHandle_ = 0;
	Model* model_ = nullptr;

	ViewProjection viewProjection_;


	bool isDebugCameraActive_ = false;

	DebugCamera* debugCamera_ = nullptr;

	Sprite* title_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
	/// 
	

};
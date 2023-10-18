#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Player.h"
#include "DebugCamera.h"
#include"Stage.h"
#include"Road.h"
#include "Scene.h"
#include "Enemy.h"
#include <sstream>

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

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

    /// <summary>
    /// 衝突判定と応答
    /// </summary>
	void CheckAllCollision();

	bool isSceneEnd = false;
	bool IsSceneEnd() { return isSceneEnd; }

	bool isGameOver = false;
	bool IsGameOver() { return isGameOver; }


	SceneType NextScene() {

		if (isSceneEnd == true) {
		return SceneType::kClearGame;
		} else
		if (isGameOver == true) {
		return SceneType::kGameOver;
		}
		return SceneType::kGamePlay;
	}



	/// <summary>
	/// 敵発生
	/// </summary>
	void EnemyPop(Vector3 pos);

    /// <summary>
    /// 敵発生データの読み込み
    /// </summary>
	void LoadEnemyPopData();

    /// <summary>
    /// 敵発生コマンドの更新
    /// </summary>
	void UpdateEnemyPopCommands();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	uint32_t textureHandle_ = 0;
	Model* model_ = nullptr;

	ViewProjection viewProjection_;
	Player* player_ = nullptr;

	Enemy* enemy_ = nullptr;

	std::list<Enemy*> enemys_;
	// 敵発生コマンド
	std::stringstream enemyPopCommands;

	Stage* stage_ = nullptr; // ステージ

	Road* road_ = nullptr;
	Model* modelRoad_ = nullptr;

	bool isDebugCameraActive_ = false;

	DebugCamera* debugCamera_ = nullptr;

	// 待機中フラグ
	bool isWaiting_;
	// 待機タイマー
	int32_t waitTimer_;

	//clearTimer_の待機秒
	int timeSe_;
	//Clearへ行くTimer
	int clearTimer_;


	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include "Function.h"

// 前方宣言
class GameScene;

class Enemy {
public:
	void Initialize(Model* model, const Vector3& position);
	void Update();
	void Draw(ViewProjection& viewProjection);
	// 衝突を検出したら呼び出されるコールバック関数
	void OnCollision();
	// ワールド座標を取得
	Vector3 GetWorldPosition();
	bool IsDead() const { return isDead_; }

	void SetGameScene(GameScene* gameScene) { gameScene_ = gameScene; }

private:
	WorldTransform worldTransform_;
	Model* model_;
	//uint32_t textureHandle_ = 0u;
	// デスフラグ
	bool isDead_ = false;
	// ゲームシーン
	GameScene* gameScene_ = nullptr;
};

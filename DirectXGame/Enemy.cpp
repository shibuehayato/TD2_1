#include "Enemy.h"
#include "cassert"

void Enemy::Initialize(Model* model)
{
	assert(model);

	model_ = model;

	textureHandle_ = TextureManager::Load("uvChecker.png");
	worldTransform_.scale_ = {0.4f, 0.4f, 0.4f};
	worldTransform_.translation_ = {1, 0, 0};
	worldTransform_.Initialize();
}

void Enemy::Update()
{
	Vector3 move = {0, 0, 0};

	// 敵の移動の速さ
	const float kCharacterSpeed = 0.2f;

	move.z = kCharacterSpeed;

	worldTransform_.translation_.z -= move.z; 

	worldTransform_.matWorld_ = MakeAffineMatrix(
	    worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

	worldTransform_.TransferMatrix();
}

void Enemy::Draw(ViewProjection& viewProjection) {

	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}
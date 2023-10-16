#include "Enemy.h"
#include "cassert"

void Enemy::Initialize(Model* model, const Vector3& position) {
	assert(model);

	model_ = model;
	// 引数で初期座標をリセット
	worldTransform_.translation_ = position;
	textureHandle_ = TextureManager::Load("uvChecker.png");
	worldTransform_.scale_ = {1.0f, 1.0f, 1.0f};
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

	if (isDead_ == false) 
	{
		model_->Draw(worldTransform_, viewProjection, textureHandle_);
	}
}

Vector3 Enemy::GetWorldPosition() {
	// ワールド座標を入れる変数
	Vector3 worldPos;
	// ワールド行列の平行移動成分を取得　(ワールド座標)
	worldPos.x = worldTransform_.matWorld_.m[3][0];
	worldPos.y = worldTransform_.matWorld_.m[3][1];
	worldPos.z = worldTransform_.matWorld_.m[3][2];

	return worldPos;
}

void Enemy::OnCollision() { isDead_ = true; }
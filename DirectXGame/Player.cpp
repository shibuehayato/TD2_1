#include "Player.h"
#include"cassert"
#include "ImGuiManager.h"

void Player::Initalize(Model* model) {
	
	assert(model); 
	
	model_ = model;

	textureHandle_ = TextureManager::Load("white1x1.png");

worldTransform_.scale_ = {1.0f, 1.0f, 1.0f};

worldTransform_.rotation_ = {0.0f, 0.0f, 0.0f};

worldTransform_.translation_ = {1.0f, 1.0f, 1.0f};

worldTransform_.Initialize();

input_ = Input::GetInstance();


}

void Player::Update() {

	Vector3 move = {0, 0, 0};

const float kCharacterSpeed = 0.2f;

if (input_->PushKey(DIK_A)) {
	move.x -= kCharacterSpeed;
} else if (input_->PushKey(DIK_D)) {
	move.x += kCharacterSpeed;
}
if (input_->PushKey(DIK_W)) {
	move.y += kCharacterSpeed;
} else if (input_->PushKey(DIK_S)) {
	move.y -= kCharacterSpeed;
}
worldTransform_.translation_.x += move.x;
worldTransform_.translation_.y += move.y;
worldTransform_.translation_.z += move.z;

const float kMoveLimitX = 20;
const float kMoveLimitY = 18;

worldTransform_.translation_.x = max(worldTransform_.translation_.x, -kMoveLimitX);
worldTransform_.translation_.x = min(worldTransform_.translation_.x, +kMoveLimitX);
worldTransform_.translation_.y = max(worldTransform_.translation_.y, -kMoveLimitY);
worldTransform_.translation_.y = min(worldTransform_.translation_.y, +kMoveLimitY);

worldTransform_.matWorld_ = MakeAffineMatrix(
	worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

worldTransform_.TransferMatrix();

}

void Player::Draw(ViewProjection& viewProjection) {

	model_->Draw(worldTransform_, viewProjection, textureHandle_);

}

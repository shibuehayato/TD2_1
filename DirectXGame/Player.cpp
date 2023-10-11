#include "Player.h"
#include "ImGuiManager.h"
#include "cassert"

void Player::Initalize(Model* model) {

	assert(model);

	model_ = model;

	textureHandle_ = TextureManager::Load("white1x1.png");

	worldTransform_.scale_ = {3.0f, 3.0f, 3.0f};

	worldTransform_.rotation_ = {0.0f, 0.0f, 0.0f};

	worldTransform_.translation_ = {0.0f, 0.0f, 0.0f};

	worldTransform_.Initialize();

	input_ = Input::GetInstance();
}

void Player::Update() {

	Vector3 move = {0, 0, 0};
	

	const float kCharacterSpeed = 0.3f;

	if (input_->PushKey(DIK_A)) {
		move.x -= kCharacterSpeed;

	} else if (input_->PushKey(DIK_D)) {
		move.x += kCharacterSpeed;
	}

	if (input_->TriggerKey(DIK_SPACE) && worldTransform_.translation_.y == 0) {
		velocity.y = 5.0f;
	}

	velocity.y += acceleration.y;

	worldTransform_.translation_.y += velocity.y;

	if (worldTransform_.translation_.y <= 0) {
		worldTransform_.translation_.y = 0;
	}

	worldTransform_.translation_.x += move.x;
	worldTransform_.translation_.y += move.y;
	worldTransform_.translation_.z += move.z;

	/*const float kMoveLimitX = 20;

	const float kMoveLimitY = 18;*/

	/*worldTransform_.translation_.x = max(worldTransform_.translation_.x, -kMoveLimitX);
	worldTransform_.translation_.x = min(worldTransform_.translation_.x, +kMoveLimitX);
	worldTransform_.translation_.y = max(worldTransform_.translation_.y, -kMoveLimitY);
	worldTransform_.translation_.y = min(worldTransform_.translation_.y, +kMoveLimitY);*/

	worldTransform_.matWorld_ = MakeAffineMatrix(
	    worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

	worldTransform_.TransferMatrix();

	ImGui::Begin("du");
	ImGui::Text(
	    " x: %f,y: %f z: %f", worldTransform_.translation_.x, worldTransform_.translation_.y,
	    worldTransform_.translation_.z);
	ImGui::DragFloat3("Translation", &worldTransform_.translation_.x, 0.01f);
	ImGui::DragFloat3("Rotation", &worldTransform_.rotation_.x, 0.01f);

	ImGui::End();
}

void Player::Draw(ViewProjection& viewProjection) {

	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}

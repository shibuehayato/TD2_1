#include "Player.h"

void Player::Initalize() {

worldTransform_.scale_ = {1.0f, 1.0f, 1.0f};

worldTransform_.rotation_ = {0.0f, 0.0f, 0.0f};

worldTransform_.translation_ = {0.0f, 0.0f, 0.0f};


}

void Player::Update() {



}

void Player::Draw(ViewProjection& viewProjection) {

	model_->Draw(worldTransform_, viewProjection, textureHandle_);

}

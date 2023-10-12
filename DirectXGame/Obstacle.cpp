#include "Obstacle.h"
#include "cassert"
#include "ImGuiManager.h"
#include "Player.h"
#include"GameScene.h"

void Obstacle::Initialize(Model* model, uint32_t textureHandle, Vector3 enemyPosition) { 
	assert(model);

	model_ = model;

	textureHandle_ = textureHandle;

	worldTransform_.Initialize();

	worldTransform_.scale_ = {3.0f, 3.0f, 3.0f};

	worldTransform_.rotation_ = {0.0f, 0.0f, 0.0f};

	worldTransform_.translation_ = enemyPosition;


}

void Obstacle::Update() { 
	

}

void Obstacle::Draw(const ViewProjection& viewProjection) {

	model_->Draw(worldTransform_, viewProjection, textureHandle_);


}

Obstacle::~Obstacle() {



}

void Obstacle::OnColision() {


}

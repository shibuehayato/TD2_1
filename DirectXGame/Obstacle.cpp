#include "Obstacle.h"
#include "cassert"
#include "ImGuiManager.h"
#include "Player.h"
#include"GameScene.h"

void Obstacle::Initialize(Model* model, uint32_t textureHandle, Vector3 enemyPosition) { 
	assert(model);

	model_ = model;

	textureHandle_ = textureHandle;



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

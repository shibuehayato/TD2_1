#include "Road.h"
#include<cassert>



void Road::Initialize(Model* model) { 
	assert(model);
	model_ = model;
	textureHandle_ = TextureManager::Load("stage2.jpg");
	
	worldTransform_.Initialize();
	worldTransform_.translation_ = {0, -1.5f, -10};
	worldTransform_.scale_ = {4.5f, 1, 40};
	worldTransform_.matWorld_ = MakeAffineMatrix(
	    worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	worldTransform_.TransferMatrix();
}

void Road::Update() {

	worldTransform_.matWorld_ = MakeAffineMatrix(
	    worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

	worldTransform_.TransferMatrix();
}

void Road::Draw3D(ViewProjection& viewProjection) {
	//
	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}
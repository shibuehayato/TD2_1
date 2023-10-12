#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include "Function.h"

class Enemy {
public:
	void Initialize(Model* model);
	void Update();
	void Draw(ViewProjection& viewProjection);

private:
	WorldTransform worldTransform_;
	Model* model_;
	uint32_t textureHandle_ = 0u;

};

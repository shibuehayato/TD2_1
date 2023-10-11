#pragma once
#include"Model.h"
#include"WorldTransform.h"
#include"Input.h"
#include "Function.h"

class Player {

public:

	void Initalize(Model*model);

	void Update();

	void Draw(ViewProjection& viewProjection);

private:

	WorldTransform worldTransform_;

	Model* model_ = nullptr;

	uint32_t textureHandle_ = 0u;

	Input* input_ = nullptr;

	Vector3 velocity = {0, 0, 0};
	Vector3 acceleration = {0, -0.4f, 0};

};

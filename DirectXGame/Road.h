#pragma once

#include "Model.h"
#include"WorldTransform.h"
#include "Function.h"

class Road {
public:
	/// <summary>
	/// 
	/// </summary>
	void Initialize(Model* model);

	/// <summary>
	/// 
	/// </summary>
	void Update();

	/// <summary>
	/// 
	/// </summary>
	void Draw3D(ViewProjection& viewProjection);

	private:
		//
	    WorldTransform worldTransform_;
		//
	    Model* model_;
		//
	    uint32_t textureHandle_ = 0u;


};

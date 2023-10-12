#pragma once
#include "Input.h"
#include "Model.h"
#include "WorldTransform.h"
#include <list>
#include "Function.h"
class Player;
class GameScene;

class Obstacle {

	public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="model">モデル</param>
	void Initialize(Model* model, uint32_t textureHandle, Vector3 enemyPosition);
	/// <summary>
	/// 更新
	/// </summary>
	void Update();
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="viewProjection">ビュープロジェクション</param>
	void Draw(const ViewProjection& viewProjection);

	~Obstacle();

	void OnColision();


	private:


		WorldTransform worldTransform_;

	    Model* model_ = nullptr;

	    uint32_t textureHandle_ = 0u;

	    Input* input_ = nullptr;

		Player* player_ = nullptr;

	    GameScene* gameScene_ = nullptr;


};

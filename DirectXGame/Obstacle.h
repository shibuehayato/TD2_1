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
	/// ������
	/// </summary>
	/// <param name="model">���f��</param>
	void Initialize(Model* model, uint32_t textureHandle, Vector3 enemyPosition);
	/// <summary>
	/// �X�V
	/// </summary>
	void Update();
	/// <summary>
	/// �`��
	/// </summary>
	/// <param name="viewProjection">�r���[�v���W�F�N�V����</param>
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

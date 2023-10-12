#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include "AxisIndicator.h"

GameScene::GameScene() {}

GameScene::~GameScene() { 
	delete model_;
	delete player_;
	delete debugCamera_;

}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	model_ = Model::Create();

	viewProjection_.Initialize();

	player_ = new Player();

	player_->Initalize(model_);

	debugCamera_ = new DebugCamera(1280, 720);

	AxisIndicator::GetInstance()->SetVisible(true);
	AxisIndicator::GetInstance()->SetTargetViewProjection(&viewProjection_);



}

void GameScene::Update() {

	player_->Update();

	#ifdef _DEBUG

	if (input_->PushKey(DIK_E)) {
	    isDebugCameraActive_ = true;
	}

#endif // DEBUG

	if (isDebugCameraActive_ == true) {
		debugCamera_->Update();
		viewProjection_.matView = debugCamera_->GetViewProjection().matView;
		viewProjection_.matProjection = debugCamera_->GetViewProjection().matProjection;

		viewProjection_.TransferMatrix();
	} else {

		viewProjection_.UpdateMatrix();
	}


}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	player_->Draw(viewProjection_);



	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}

void GameScene::CheckAllColisions() { 
	
	Vector3 posA, posB;

	#pragma region // 自キャラと敵弾の当たり判定
	//posA = player_->GetWorldPosition();

	//for (Enemy* enemy : enemys_) {
	//	posB = enemy->GetWorldPosition();

	//	float X = (posB.x - posA.x);
	//	float Y = (posB.y - posA.y);
	//	float Z = (posB.z - posA.z);

	//	float center = X * X + Y * Y + Z * Z;
	//	float R1 = 3.0f; // 自分で決める
	//	float R2 = 1.0f; // 自分で決める
	//	float RR = (R1 + R2);

	//	if (center <= (RR * RR)) {
	//		// 自キャラの衝突時コールバックを呼び出す
	//		player_->OnColision();
	//		// 敵の衝突時コールバックを呼び出す
	//		bullet->OnColision();
	//	}
	//}
#pragma endregion

}

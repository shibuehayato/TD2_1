#include "GameOverScean.h"

GameOverScean::GameOverScean() {}

GameOverScean::~GameOverScean() {

delete gameOver_;

}

void GameOverScean::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	// レティクル用テクスチャ取得
	uint32_t textureTitle = TextureManager::Load("GameOver.png");

	gameOver_ = Sprite::Create(textureTitle, {640.0f, 360.0f}, {1.0f, 1.0f, 1.0f, 1}, {0.5f, 0.5f});
	
	soundDataHandle_ = audio_->LoadWave("kaisou.wav");

	/*voiceHandle_ = audio_->PlayWave(soundDataHandle_, true);

	audio_->PauseWave(voiceHandle_);*/

}

void GameOverScean::Update() {

	if (!audio_->IsPlaying(voiceHandle_)) {

		voiceHandle_ = audio_->PlayWave(soundDataHandle_);
	}

if (input_->TriggerKey(DIK_SPACE)) {

	audio_->StopWave(voiceHandle_);

		
		isSceneEnd = true;
	} else {

		isSceneEnd = false;
	}


}

void GameOverScean::Draw() {

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

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる

	gameOver_->Draw();

	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion

}

#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include "AxisIndicator.h"
#include <fstream>

GameScene::GameScene() {}

GameScene::~GameScene() {
	delete model_;
	delete player_;
	delete debugCamera_;
	delete stage_; // ステージ
	delete road_;
	
	for (Enemy* enemy : enemys_) {
		delete enemy;
	}

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

	modelRoad_ = Model::Create();
	stage_ = new Stage();
	stage_->Initialize(); // ステージ

	road_ = new Road();//道
	road_->Initialize(modelRoad_);
	
	viewProjection_.translation_.y=2;
	
	viewProjection_.rotation_;
	

	AxisIndicator::GetInstance()->SetVisible(true);
	AxisIndicator::GetInstance()->SetTargetViewProjection(&viewProjection_);

	LoadEnemyPopData();

	timeSe_ = 10;
	clearTimer_ = timeSe_ * 60;

	/*isWaiting_ = false;
	waitTimer_ = 0;*/
	enemyPopCommands = {};


}

void GameScene::Update() {

	player_->Update();
	stage_->Update();
	road_->Update();
	
	// 敵キャラの更新
	UpdateEnemyPopCommands();
	for (Enemy* enemy : enemys_) {
		enemy->Update();
	}

	CheckAllCollision();

	clearTimer_--;

	if (clearTimer_ <= 0) {
		clearTimer_ = timeSe_ * 60;
	isSceneEnd = true;
	
	}
	else
	if (isSceneEnd == true) {
	
	isSceneEnd = false;
	}



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
	stage_->Draw2DFar();
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
	road_->Draw3D(viewProjection_);

	// 敵キャラの描画
	for (Enemy* enemy : enemys_) {
		enemy->Draw(viewProjection_);
	}

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

void GameScene::CheckAllCollision()
{
	float playerRadius = 0.4f;
	float enemyRadius = 0.4f;

	// 判定対象AとBの座標
	Vector3 posA, posB;

	#pragma region 自キャラと敵弾の当たり判定
	// 自キャラの座標
	posA = player_->GetWorldPosition();

	// 自キャラと敵弾全ての当たり判定
	for (Enemy* enemy : enemys_) {
		// 敵弾の座標
		posB = enemy->GetWorldPosition();

		// 座標AとBの距離を求める
		Vector3 Distance = {
		    (posA.x - posB.x) * (posA.x - posB.x), (posA.y - posB.y) * (posA.y - posB.y),
		    (posA.z - posB.z) * (posA.z - posB.z)};

		if (Distance.x + Distance.y + Distance.z <=
		    (playerRadius + enemyRadius) * (playerRadius + enemyRadius)) {
			// 自キャラの衝突時コールバック関数を呼び出す
			player_->OnCollision();
			// 敵弾の衝突時コールバック関数を呼び出す
			enemy->OnCollision();
		}
	}
#pragma endregion

}

void GameScene::EnemyPop(Vector3 position) {
	// 敵キャラの生成
	enemy_ = new Enemy();
	// 敵キャラの初期化
	enemy_->Initialize(model_, position);
	// 敵キャラにゲームシーンを渡す
	enemy_->SetGameScene(this);
	enemys_.push_back(enemy_);
}


void GameScene::LoadEnemyPopData() {
	// ファイルを開く
	std::ifstream file;
	file.open("Resources/enemyPop.csv");
	assert(file.is_open());

	// ファイルの内容を文字列ストリームにコピー
	enemyPopCommands << file.rdbuf();

	// ファイルを閉じる
	file.close();
}

void GameScene::UpdateEnemyPopCommands() {
	// 待機処理
	if (isWaiting_) {
		waitTimer_--;
		if (waitTimer_ <= 0) {
			// 待機完了
			isWaiting_ = false;
		}
		return;
	}

	// 1行分の文字列を入れる変数
	std::string line;

	// コマンド実行ループ
	while (getline(enemyPopCommands, line)) {
		// 1行分の文字列をストリームに変換して解析しやすくする
		std::istringstream line_stream(line);

		std::string word;
		// ,区切りで行の先頭文字列を取得
		getline(line_stream, word, ',');

		// "//"から始まる行はコメント
		if (word.find("//") == 0) {
			// コメント行を飛ばす
			continue;
		}

		// POPコマンド
		if (word.find("POP") == 0) {
			// x座標
			getline(line_stream, word, ',');
			float x = (float)std::atof(word.c_str());

			// y座標
			getline(line_stream, word, ',');
			float y = (float)std::atof(word.c_str());

			// z座標
			getline(line_stream, word, ',');
			float z = (float)std::atof(word.c_str());

			// 敵を発生させる
			EnemyPop(Vector3(x, y, z));
		}

		// WAITコマンド
		else if (word.find("WAIT") == 0) {
			getline(line_stream, word, ',');

			// 待ち時間
			int32_t waitTime = atoi(word.c_str());

			// 待機開始
			isWaiting_ = true;
			waitTimer_ = waitTime;

			// コマンドループを抜ける
			break;
		}
	}
}
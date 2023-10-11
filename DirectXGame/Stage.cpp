#include "Stage.h"
/// <summary>
/// コンストラクタ
/// </summary>
Stage::Stage() {}

/// <summary>
/// デストラクタ
/// </summary>
Stage::~Stage() { 
	delete spriteBG_;
}

/// <summary>
/// 初期化
/// </summary>
void Stage::Initialize() {
	//BG(2Dスプライト)
	textureHandleBG_ = TextureManager::Load("bg.jpg");
	spriteBG_ = Sprite::Create(textureHandleBG_, {0, 0});
}
/// <summary>
/// 更新
/// </summary>
void Stage::Update() {
	
}
/// <summary>
/// 2D背景描画
/// </summary>
void Stage::Draw2DFar() {
	//背景
	spriteBG_->Draw();
}
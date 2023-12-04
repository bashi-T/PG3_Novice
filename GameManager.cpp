#include "GameManager.h"

GameManager::GameManager() {
	sceneArr_[TITLE] = std::make_unique<TitleScene>(); 
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();
}

GameManager::~GameManager() {}

int GameManager::run()
{
	while (Novice::ProcessMessage() == 0)
	{
		Novice::BeginFrame();
		inputManager_->Update();
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();
		if (prevSceneNo_ != currentSceneNo_)
		{
			sceneArr_[currentSceneNo_]->Initialize();
		}
		sceneArr_[currentSceneNo_]->Update();
		sceneArr_[currentSceneNo_]->Draw();

		Novice::EndFrame();
		if (inputManager_->GetPreKeys()[DIK_SPACE] == 0 &&
		    inputManager_->GetKeys()[DIK_SPACE] != 0)
		{
			break;
		}
	}
	return 0;
}

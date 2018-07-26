#pragma once

#include "ISceneChanger.h"
#include "Task.h"

class BaseScene : public Task {
public:
	BaseScene(ISceneChanger* changer);
	virtual ~BaseScene() {}
	virtual void Initialize() override {}
	virtual void Finalize() override;
	virtual void Update() override {}
	virtual void Draw() override;

protected:
	ISceneChanger *mSceneChanger;    //クラス所有元にシーン切り替えを伝えるインターフェイス
};

BaseScene::BaseScene(ISceneChanger *changer) {
	this->mSceneChanger = changer;
}

#pragma once

#include "Scene.h"
#include "DxLib.h"

class Title : public BaseScene {
public:
	Title(ISceneChanger *changer);
	~Title() {}

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

};

Title::Title(ISceneChanger *changer) : BaseScene(changer) {

}

void Title::Initialize() {

}

void Title::Update() {

}

void Title::Draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "ƒ^ƒCƒgƒ‹");
}

void Title::Finalize() {

}
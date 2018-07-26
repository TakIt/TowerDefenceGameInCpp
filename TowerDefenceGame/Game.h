#pragma once

#include "Scene.h"
#include "DxLib.h"

#include "Enemy.h"
#include "Turret.h"
#include "Terrain.h"

#include <vector>
#include <list>

class Game : public BaseScene {
public:
	Game(ISceneChanger *changer);
	~Game() {}

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

private:
	std::vector<TurretBase> vturret;
	std::vector<EnemyBase> venemy;
	std::list<Vector2D> pathlist;

};

Game::Game(ISceneChanger *changer) : BaseScene(changer) {

}

void Game::Initialize() {

}

void Game::Update() {
	for (int i = 0; i < vturret.size(); i++) {
		vturret[i].attack(venemy);
	}
	for (int i = 0; i < venemy.size(); i++) {
		venemy[i].moveTo();
	}
}

void Game::Draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "ƒQ[ƒ€");
}

void Game::Finalize() {

}
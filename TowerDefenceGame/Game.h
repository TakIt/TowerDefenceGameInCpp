#pragma once

#include "Scene.h"
#include "DxLib.h"

#include "Enemy.h"
#include "Turret.h"
#include "Terrain.h"

#include <vector>

class Game : public BaseScene {
public:
	Game(ISceneChanger *changer);
	~Game() {}

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

private:
	// turret factory
	// enemy factory


	/*
	std::vector<TurretBase> vturret;
	std::vector<EnemyBase> venemy;
	std::vector<Vector2D> vpath;
	*/

};

Game::Game(ISceneChanger *changer) : BaseScene(changer) {

}

void Game::Initialize() {

}

void Game::Update() {

}

void Game::Draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "ÉQÅ[ÉÄ");
}

void Game::Finalize() {

}
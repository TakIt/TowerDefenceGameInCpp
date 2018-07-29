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
	std::vector<Vector2D> vpath;

};

Game::Game(ISceneChanger *changer) : BaseScene(changer) {

}

void Game::Initialize() {

}

void Game::Update() {
	for (auto i = vturret.begin();i != vturret.end(); ++i) {
		i->attack(venemy);
	}
	for (auto i = venemy.begin(); i != venemy.end(); ++i) {
		i->move(vpath);
	}
}

void Game::Draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "ÉQÅ[ÉÄ");
}

void Game::Finalize() {

}
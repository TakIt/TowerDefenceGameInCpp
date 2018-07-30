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
	std::vector<TurretBase*> vturret;
	std::vector<EnemyBase*> venemy;
	std::vector<Vector2D> vpath;
	

};

Game::Game(ISceneChanger *changer) : BaseScene(changer) {

}

void Game::Initialize() {
	NormalEnemy *normalenemy = new NormalEnemy(20,1,2,10);
	Vector2D *vec = new Vector2D(0, 0);
	venemy.push_back(normalenemy);
	venemy[0]->setPosition(*vec);
	vpath.push_back(*vec);
	vec = new Vector2D(10, 10);
	vpath.push_back(*vec);
	vec = new Vector2D(30, 10);
	vpath.push_back(*vec);

}

void Game::Update() {
	venemy[0]->move(vpath);
}

void Game::Draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "ƒQ[ƒ€");
	DrawFormatString(0, 20, GetColor(255, 255, 255), "x:%lf,y:%lf,arg:%lf",venemy[0]->getPosition().getX(),venemy[0]->getPosition().getY(),venemy[0]->getPosition().getAngleTo(vpath[1]));
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", venemy[0]->getCurrentpoint());
	DrawCircle((int)venemy[0]->getPosition().getX(), (int)venemy[0]->getPosition().getY(), 2, GetColor(255, 255, 255));

	for (int i = 0; i < vpath.size(); i++) {
		DrawCircle(vpath[i].getX(), vpath[i].getY(), 2, GetColor(255, 255, 255));
	}
}

void Game::Finalize() {

}
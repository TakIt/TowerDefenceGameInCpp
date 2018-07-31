#pragma once

#include "Scene.h"
#include "DxLib.h"

#include "Enemy.h"
#include "Turret.h"
#include "Terrain.h"

#include "Texture.h"

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
	
	Texture *texture;

};

Game::Game(ISceneChanger *changer) : BaseScene(changer) {

}

void Game::Initialize() {
	// for debug
	NormalEnemy *normalenemy = new NormalEnemy(20,4,2,10);
	Vector2D *vec = new Vector2D(0, 364);
	venemy.push_back(normalenemy);
	venemy[0]->setPosition(*vec);
	vpath.push_back(*vec);
	vec = new Vector2D(32*3, 364);
	vpath.push_back(*vec);
	vec = new Vector2D(32*3, 268);
	vpath.push_back(*vec);
	vec = new Vector2D(32*8, 268);
	vpath.push_back(*vec);
	vec = new Vector2D(32 * 8, 460);
	vpath.push_back(*vec);
}

void Game::Update() {
	venemy[0]->move(vpath);
}

void Game::Draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "ƒQ[ƒ€");

	// for debug
	DrawFormatString(0, 20, GetColor(255, 255, 255), "x:%lf,y:%lf,arg:%lf",venemy[0]->getPosition().getX(),venemy[0]->getPosition().getY(),venemy[0]->getAngle());
	DrawFormatString(0, 40, GetColor(255, 255, 255), "%d", venemy[0]->getCurrentpoint());
	DrawCircle((int)venemy[0]->getPosition().getX(), (int)venemy[0]->getPosition().getY(), 2, GetColor(255, 0, 0));

	for (int i = 0; i < (signed)vpath.size(); i++) {
		DrawCircle((int)vpath[i].getX(), (int)vpath[i].getY(), 2, GetColor(255, 255, 255));
	}
}

void Game::Finalize() {

}
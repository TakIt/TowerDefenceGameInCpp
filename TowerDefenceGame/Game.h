#pragma once

#include "Scene.h"
#include "DxLib.h"

#include "Enemy.h"
#include "Turret.h"
#include "Terrain.h"

#include "Texture.h"

#include <vector>

// for DxLib's Color Code
#define White GetColor(255,255,255)
#define Black GetColor(0,0,0)
#define Red GetColor(255,0,0)
#define Green GetColor(0,255,0)
#define Blue Getcolor(0,0,255)
#define Yellow GetColor(255,255,0)
#define SkyBlue GetColor(0,255,255)
#define Purple GetColor(255,0,255)


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
	std::vector<std::vector<TerrainBase*>> vterrain;
	
	Texture *texture;

};

Game::Game(ISceneChanger *changer) : BaseScene(changer) {

}

void Game::Initialize() {
	// for debug
	NormalEnemy *normalenemy = new NormalEnemy(20,8,2,10);
	Vector2D *vec = new Vector2D(80, 408);
	venemy.push_back(normalenemy);
	venemy[0]->setPosition(*vec);
	vpath.push_back(*vec);
	vec = new Vector2D(112 + 64*1, 408);
	vpath.push_back(*vec);
	vec = new Vector2D(112 + 64*1, 408 - 64*3);
	vpath.push_back(*vec);
	vec = new Vector2D(112 + 64*3, 408 - 64*3);
	vpath.push_back(*vec);
	vec = new Vector2D(112 + 64*3, 408 + 64*2);
	vpath.push_back(*vec);
	vec = new Vector2D(112 + 64*1, 408 + 64*2);
	vpath.push_back(*vec);
	vec = new Vector2D(112 + 64*1, 408 + 64*4);
	vpath.push_back(*vec);
	vec = new Vector2D(112 + 64*9, 408 + 64*4);
	vpath.push_back(*vec);
	vec = new Vector2D(112 + 64*9, 408 + 64*2);
	vpath.push_back(*vec);
	vec = new Vector2D(112 + 64*6, 408 + 64*2);
	vpath.push_back(*vec);
	vec = new Vector2D(112 + 64*6, 408 - 64*2);
	vpath.push_back(*vec);
	vec = new Vector2D(112 + 64 * 5, 408 - 64 * 2);
	vpath.push_back(*vec);
	vec = new Vector2D(112 + 64 * 5, 408 - 64 * 4);
	vpath.push_back(*vec);
	vec = new Vector2D(112 + 64 * 9, 408 - 64 * 4);
	vpath.push_back(*vec);
	vec = new Vector2D(112 + 64 * 9, 408 - 64 * 2);
	vpath.push_back(*vec);
	vec = new Vector2D(112 + 64 * 8, 408 - 64 * 2);
	vpath.push_back(*vec);
	vec = new Vector2D(112 + 64 * 8, 408 - 64 * 0);
	vpath.push_back(*vec);
	vec = new Vector2D(144 + 64 * 10, 408 - 64 * 0);
	vpath.push_back(*vec);
}

void Game::Update() {
	for (auto i = venemy.begin(); i != venemy.end(); i++) {
		(*i)->move(vpath);
	}
	for (auto i = vturret.begin(); i != vturret.end(); i++) {
		
	}
}

void Game::Draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�Q�[��");

	DrawFormatString(0, 40, White, "%lf", venemy[0]->getDistanceToBase(vpath));

	
	// Stop/Start
	DrawString(8, 8, "S/S", White);
	DrawBox(8, 8, 48, 48, White, FALSE);
	
	// FastForward
	DrawString(56, 8, "FF", White);
	DrawBox(56, 8, 96, 48, White, FALSE);

	// NextWave
	DrawString(104, 8, "NW", White);
	DrawBox(104, 8, 144, 48, White, FALSE);

	// WaveGuage
	DrawString(8, 56, "Wave", White);
	DrawBox(8, 56, 72, 768 - 8, White, FALSE);

	// Money
	DrawString(208, 8, "Money", White);
	DrawBox(208, 8, 528, 48, White, FALSE);

	// Health
	DrawString(536, 8, "Health", White);
	DrawBox(536, 8, 656, 48, White, FALSE);

	// Options
	DrawString(976, 8, "Opt", White);
	DrawBox(976, 8, 1016, 48, White, FALSE);


	// field
	DrawString(80, 56, "Field", White);
	const int Boxsize = 64;
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			DrawBox(80 + j * Boxsize, 56 + i * Boxsize, 144 + j * Boxsize, 120 + i * Boxsize, White, FALSE);
		}
	}

	// turret construction/information menu
	DrawBox(152 + 10 * Boxsize, 56, 1024 - 8, 768 - 8, White, FALSE);
	DrawBox(160 + 10 * Boxsize, 64, 1024 - 16, 348 - 16, White, FALSE);

	// turrets
	DrawString(160 + 10 * Boxsize, 64, "Turret", White);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			DrawBox(168 + 10 * Boxsize + j * 64, 132 + i * 64, 232 + 10 * Boxsize + j * 64, 196 + i * 64, White, FALSE);
		}
	}

	// info
	DrawString(160 + 10 * Boxsize, 340, "Information", White);
	DrawBox(160 + 10 * Boxsize, 340, 1024 - 16, 768 - 16, White, FALSE);

	DrawCircle((int)venemy[0]->getPosition().getX(), (int)venemy[0]->getPosition().getY(), 4, White);
}

void Game::Finalize() {

}
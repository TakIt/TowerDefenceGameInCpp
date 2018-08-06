#pragma once
#include"Enemy.h"
#include"Turret.h"
#include<vector>

class Attack {
public:
	Attack() {

	}
	~Attack();
	virtual void decisionOrder(std::vector<EnemyBase> &targetlist,Vector2D position)=0;
	virtual void decisionOrder(std::vector<EnemyBase> &targetlist) = 0;
protected:
	int targetindex;
private:
};


class AttackClosestTurret : public Attack {
public:
	void calculatedestance(Vector2D enemyposition, Vector2D turretposition) {

	}
	void decisionOrder(std::vector<EnemyBase>&targetlist, Vector2D turretposition)override {
		mindistancefromturret = destance;
		for (int i=1; i < targetlist.size(); i++) {
			if(targetlist.at(i)
		}
	}
private:
	double mindistancefromturret;
};


class AttackFarthestTurret :public Attack {
public:
	void decisionOrder(std::vector<EnemyBase>&targetlist, Vector2D turretposition)override {

	}
private:
	double maxdistancefromturret;
};


class AttackClosestBase :public Attack {
public:
	void decisionOrder(std::vector<EnemyBase>&targetlist, Vector2D baseposition)override {

	}
private:
	double mindistancefrombase;
};


class AttackFarthestTrret :public Attack {
public:
	void decisionOrder(std::vector<EnemyBase>&targetlist, Vector2D baseposition)override {

	}
private:
	double maxdistancefrombase;
};


class AttackLowestHealth :public Attack {
public:
	void decisionOrder(std::vector<EnemyBase>&targetlist)override {

	}
private:
	int minhitpoint;
};


class AttackHighestHealth :public Attack {
public:
	void decisionOrder(std::vector<EnemyBase>&targetlist)override {

	}
private:
	int maxhitpoint;
};


class AttackRandom :public Attack {
public:
	void decisionOrder(std::vector<EnemyBase>&targetlist)override {

	}
private:
};


//ゲーム自体にコンストラクタを呼ぶ関数があると想定。
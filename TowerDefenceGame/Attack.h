#pragma once
#include"Enemy.h"
#include"Turret.h"
class TurretBase;
class MortarTurret;
class TargetPriority {
public:
	TargetPriority() {

	}
	virtual ~TargetPriority() {}
	virtual int decisionOrder(std::vector<EnemyBase> &targetlist, TurretBase &turret)const=0;
	virtual int decisionOrder(std::vector<EnemyBase> &targetlist, MortarTurret &turret)const=0;
};

class ClosestTurret : public TargetPriority {
public:
	ClosestTurret() {

	}
	int decisionOrder(std::vector<EnemyBase> &targetlist, TurretBase &turret)const override;
private:
};


class FarthestTurret :public TargetPriority {
public:
	FarthestTurret() {

	}
	int decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const override;
private:
};


class ClosestBase :public TargetPriority {
public:
	int decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const override;
private:
};


class FarthestBase :public TargetPriority {
public:
	int decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const override;
private:
};


class LowestHealth :public TargetPriority {
public:
	int decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const override;
private:
};


class HighestHealth :public TargetPriority {
public:
	int decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const override;
private:
};


class Random :public TargetPriority {
public:
	int decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const override;
private:
};

class ClosestTurretRing :public TargetPriority{
public:
	int decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const override;
};
class FarthestTurretRing :public TargetPriority {
public:
	int decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const override;
};
class ClosestBaseRing :public TargetPriority {
public:
	int decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const override;
};
class FarthestBaseRing :public TargetPriority {
public:
	int decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const override;
};
class LowestHealthRing :public TargetPriority {
public:
	int decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const override;
};
class HighestHealthRing :public TargetPriority {
public:
	int decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const override;
private:
};
class RandomRing :public TargetPriority {
public:
	int decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const override;
private:
};
//ゲーム自体にコンストラクタを呼ぶ関数があると想定。
#pragma once
#include"Enemy.h"
#include"Turret.h"
#include"DxLib.h"
class TurretBase;
class MortarTurret;
class TargetPriority {
public:
	TargetPriority(std::vector<Vector2D> &vpath) {
		this->vpath = vpath;
	}
	virtual ~TargetPriority() {}
	virtual int decisionOrder(std::vector<EnemyBase> &targetlist, TurretBase &turret)const;
	virtual int decisionOrder(std::vector<EnemyBase> &targetlist, MortarTurret &turret)const;
protected:
	std::vector<Vector2D> vpath;
};

class ClosestTurret : public TargetPriority {
public:
	ClosestTurret(std::vector<Vector2D> &vpath):TargetPriority(vpath) {
		
	}
	int decisionOrder(std::vector<EnemyBase> &targetlist, TurretBase &turret)const override;
private:
};


class FarthestTurret :public TargetPriority {
public:
	FarthestTurret(std::vector<Vector2D> &vpath) :TargetPriority(vpath) {

	}
	int decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const override;
private:
};


class ClosestBase :public TargetPriority {
public:
	ClosestBase(std::vector<Vector2D> &vpath) :TargetPriority(vpath) {

	}
	int decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const override;
private:
};


class FarthestBase :public TargetPriority {
public:
	FarthestBase(std::vector<Vector2D> &vpath) :TargetPriority(vpath) {

	}
	int decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const override;
private:
};


class LowestHealth :public TargetPriority {
public:
	LowestHealth(std::vector<Vector2D> &vpath) :TargetPriority(vpath) {

	}
	int decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const override;
private:
};


class HighestHealth :public TargetPriority {
public:
	HighestHealth(std::vector<Vector2D> &vpath) :TargetPriority(vpath) {

	}
	int decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const override;
private:
};


class Random :public TargetPriority {
public:
	Random(std::vector<Vector2D> &vpath) :TargetPriority(vpath) {
		SRand(0);
	}
	int decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const override;
private:
};

class ClosestTurretRing :public TargetPriority{
public:
	ClosestTurretRing(std::vector<Vector2D> &vpath) :TargetPriority(vpath) {

	}
	int decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const override;
};
class FarthestTurretRing :public TargetPriority {
public:
	FarthestTurretRing(std::vector<Vector2D> &vpath) :TargetPriority(vpath) {

	}
	int decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const override;
};
class ClosestBaseRing :public TargetPriority {
public:	
	ClosestBaseRing(std::vector<Vector2D> &vpath) :TargetPriority(vpath) {
	
	}
	int decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const override;
};
class FarthestBaseRing :public TargetPriority {
public:
	FarthestBaseRing(std::vector<Vector2D> &vpath) :TargetPriority(vpath) {

	}
	int decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const override;
};
class LowestHealthRing :public TargetPriority {
public:
	LowestHealthRing(std::vector<Vector2D> &vpath) :TargetPriority(vpath) {

	}
	int decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const override;
};
class HighestHealthRing :public TargetPriority {
public:
	HighestHealthRing(std::vector<Vector2D> &vpath) :TargetPriority(vpath) {

	}
	int decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const override;
private:
};
class RandomRing :public TargetPriority {
public:
	RandomRing(std::vector<Vector2D> &vpath) :TargetPriority(vpath) {
		SRand(0);
	}
	int decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const override;
private:
};
//ゲーム自体にコンストラクタを呼ぶ関数があると想定。
#pragma once



#include <vector>
#include <string>
#include<math.h>

#include "Vector2D.h"
#include "Enemy.h"
#include "TurretBarrel.h"
#include "Attack.h"
class TargetPriority;
class TurretBase {
public:
	TurretBase(std::string name, double damage, double firerate, double range) {
		this->name = name;
		this->damage = damage;
		this->firerate = firerate;
		this->range = range;
	}
	virtual ~TurretBase() = 0;

	virtual void attack(std::vector<EnemyBase> &targetlist) = 0;
	virtual void construct() = 0;
	bool canConstruct(long long resource);
	virtual void upgrade() = 0;
	bool canUpgrade(long long resource);
	virtual int destroy() = 0;

	std::string getName() const { return this->name; }
	double getDamage() const { return this->damage; }
	double getFireRate() const { return this->firerate; }
	double getRange() const { return this->range; }
	double getWaiting()const { return this->waiting; }
	int getGrade()const { return this->grade; }
	int getConstructCost()const { return this->constructcost; }
	int getUpgradeCost()const { return this->upgradecost; }
	int getCostSpent()const { return this->costspent; }
	Vector2D getPosition() const { return this->position; }

	void setAttackPower(double damage) { this->damage = damage; }
	void setFireRate(double firerate) { this->firerate = firerate; }
	void setAttackRange(double range) { this->range = range; }
	void setTarget(TargetPriority* priority) {this->target = priority;}
	void setWaiting(double waiting) { this->waiting = waiting; }
	void setGrade(int grade) { this->grade = grade; }
	void setDamage(double damage) { this->damage = damage; }
	void setCostSpent(int coatspent) { this->costspent = costspent; }
	void setUpgradeCost(int upgradecost) { this->upgradecost = upgradecost; }
	void setRange(double range) { this->range = range; }



protected:

	std::string name;
	int constructcost;
	int upgradecost;
	int costspent;
	int grade;
	double damage;
	double firerate;
	double range;
	double waiting;
	Vector2D position;
	TurretBarrel turretbarrel;
	TargetPriority* target;
	int texturehandle;

	
};

/// <summary>
/// BasicTurret Class.
/// </summary>
class BasicTurret : public TurretBase {
public:
	BasicTurret(std::string name, double damage, double firerate, double range,int constructcost,int upgradecost) : TurretBase(name, damage, firerate, range) {
		this->constructcost = constructcost;
		this->upgradecost = upgradecost;
	}
	~BasicTurret() {}

	void attack(std::vector<EnemyBase> &targetlist) override;
	void construct()override;
	void upgrade()override;
	int destroy()override;


protected:

};

/// <summary>
/// Turret that takes splash damage but range is restricted.
/// </summary>
class MortarTurret : public TurretBase {
public:
	MortarTurret(std::string name, double damage, double firerate, double maxrange, double splashdamage, double splashrange, double minrange) : TurretBase(name, damage, firerate, maxrange) {
		this->splashdamage = splashdamage;
		this->splashrange = splashrange;
		this->minrange = minrange;
	}
	~MortarTurret() {}
	void construct()override;
	void upgrade()override;
	int destroy()override;
	void attack(std::vector<EnemyBase> &targetlist) override;
	double getMinRange() { return this->minrange; }
	double getSplashDamage() { return this->splashdamage; }
	double getSplashRange() { return this->splashrange; }
	void setSplashDamage(double splashdamage) {this->splashdamage=splashdamage; }
	void setSplashRange(double splashrange) { this->splashrange = splashrange; }
	void setMinRange(double minrange) { this->minrange = minrange; }

protected:
	double splashdamage;
	double splashrange;
	double minrange;
};

/// <summary>
/// Turret that takes damage to all enemies in range.
/// </summary>
class BlastTurret : public TurretBase {
public:
	BlastTurret(std::string name, double damage, double firerate, double range) : TurretBase(name, damage, firerate, range) {
		
	}
	~BlastTurret() {}
	void construct()override;
	void upgrade()override;
	int destroy()override;
	void attack(std::vector<EnemyBase> &targetlist) override;

protected:
	
};

/// <summary>
/// Turret that takes damage to enemy over time
/// </summary>
class DotTurret : public TurretBase {
public:
	DotTurret(std::string name, double damage, double firerate, double range, double effectvalue) : TurretBase(name, damage, firerate, range) {
		this->effectvalue = effectvalue;
	}

	void attack(std::vector<EnemyBase> &targetlist) override;

protected:
	double effectvalue;

};
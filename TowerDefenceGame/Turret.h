#pragma once

#include "Vector2D.h"
#include "Enemy.h"
#include "TurretBarrel.h"

#include <vector>
#include <string>

class TurretBase {
public:
	TurretBase(double damage, double firerate, double range) {
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
	virtual void destroy() = 0;

	std::string getName() const { return this->name; }
	double getDamage() const { return this->damage; }
	double getFireRate() const { return this->firerate; }
	double getRange() const { this->range; }
	Vector2D getPosition() const { return this->position; }

	void setAttackPower(double damage) { this->damage = damage; }
	void setFireRate(double firerate) { this->firerate = firerate; }
	void setAttackRange(double range) { this->range = range; }


protected:
	typedef enum {
		ClosestTurret,
		FarthestTurret,
		ClosestBase,
		FarthestBase,
		LowestHealth,
		HighestHealth,

		Random,
	}eTargetPriority;

	std::string name;
	int constructcost;
	int upgradecost;
	int costspent;
	double damage;
	double firerate;
	double range;
	Vector2D position;
	eTargetPriority targetpriority;
	TurretBarrel turretbarrel;

	int texturehandle;

	
};

/// <summary>
/// BasicTurret Class.
/// </summary>
class BasicTurret : public TurretBase {
public:
	BasicTurret(double damage, double firerate, double range) : TurretBase(damage, firerate, range) {}
	~BasicTurret() {}

	void attack(std::vector<EnemyBase> &targetlist) override;


protected:

};

/// <summary>
/// Turret that takes splash damage but range is restricted.
/// </summary>
class MortarTurret : public TurretBase {
public:
	MortarTurret(double damage, double firerate, double maxrange, double splashdamage, double splashrange, double minrange) : TurretBase(damage, firerate, maxrange) {
		this->splashdamage = splashdamage;
		this->splashrange = splashrange;
		this->minrange = minrange;
	}
	~MortarTurret() {}

	void attack(std::vector<EnemyBase> &targetlist) override;

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
	BlastTurret(double damage, double firerate, double range) : TurretBase(damage, firerate, range) {
		
	}
	~BlastTurret() {}

	void attack(std::vector<EnemyBase> &targetlist) override;

protected:
	
};

/// <summary>
/// Turret that takes damage to enemy over time
/// </summary>
class DotTurret : public TurretBase {
public:
	DotTurret(double damage, double firerate, double range, double effectvalue) : TurretBase(damage, firerate, range) {
		this->effectvalue = effectvalue;
	}

	void attack(std::vector<EnemyBase> &targetlist) override;

protected:
	double effectvalue;

};
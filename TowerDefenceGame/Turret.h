#pragma once

#include "Vector2D.h"
#include "Enemy.h"
#include <string>

class TurretBase {
public:
	TurretBase() {}
	virtual ~TurretBase() {}

	virtual void attack(EnemyBase &target) = 0;
	virtual void construct() = 0;
	bool canConstruct(long long resource);
	virtual void upgrade() = 0;
	virtual void destroy() = 0;

	std::string getName() const { return this->name; }
	double getAttackPower() const { return this->attackpower; }
	double getFireRate() const { return this->firerate; }
	double getAttackRange() const { this->attackrange; }
	Vector2D getPosition() const { this->position; }


	void setAttackPower(double attackpower) { this->attackpower = attackpower; }
	void setFireRate(double firerate) { this->firerate = firerate; }
	void setAttackRange(double attackrange) { this->attackrange = attackrange; }


protected:
	typedef enum {
		ClosestTurret,
		FarthestTurret,
		ClosestBase,
		FarthestBase,

		Random,
	}eTargetPriority;

	std::string name;
	int cost;
	int costspent;
	double attackpower;
	double firerate;
	double attackrange;
	Vector2D position;
	eTargetPriority targetpriority;
	int texturehandle;

	
};

class LaserTurret : public TurretBase {
public:
	LaserTurret();
	~LaserTurret();


private:

};
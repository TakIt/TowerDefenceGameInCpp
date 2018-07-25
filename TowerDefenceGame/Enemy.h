#pragma once

#include "Vector2D.h"


/// <summary>
/// Enemy prototype
/// </summary>
class EnemyBase {
public:
	EnemyBase() {}
	EnemyBase(double hitpoint, double movespeed, double attackpower) {
		this->hitpoint = hitpoint;
		this->movespeed = movespeed;
		this->attackpower = attackpower;
	}
	virtual ~EnemyBase() {}

	virtual void moveTo(const Vector2D &target);
	bool isAlive() const { return hitpoint > 0; }


	double getHitPoint() { return this->hitpoint; }
	Vector2D getPosition() const { return this->position; }

	void setHitPoint(double hitpoint) { this->hitpoint = hitpoint; }

protected:
	double hitpoint;
	double movespeed;
	double attackpower;
	Vector2D position;
};
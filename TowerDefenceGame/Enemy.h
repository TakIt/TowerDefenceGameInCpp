#pragma once

#include "Vector2D.h"


/// <summary>
/// Enemy prototype
/// </summary>
class EnemyBase {
public:
	EnemyBase();
	EnemyBase(double hitpoint, double movespeed, double attackpower);
	virtual ~EnemyBase();

	virtual void moveTo(const Vector2D &target);
	bool isAlive() const { return hitpoint > 0; }
	Vector2D getPosition() const { return this->position; }

protected:
	double hitpoint;
	double movespeed;
	double attackpower;
	Vector2D position;
};
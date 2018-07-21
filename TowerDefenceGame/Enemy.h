#pragma once

#include "Vector2D.h"

class NormalEnemy {
public:
	NormalEnemy();
	virtual ~NormalEnemy();

	virtual void moveTo(const Vector2D &target);
	bool isAlive() const { return hitpoint > 0; }
	Vector2D getPosition() const { return this->position; }

protected:
	double hitpoint;
	double movespeed;
	int attackpower;
	Vector2D position;
};
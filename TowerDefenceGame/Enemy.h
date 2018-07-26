#pragma once

#include "Vector2D.h"

class EnemyBase {
public:
	EnemyBase(long long hitpoint, int movespeed, long attackpower, long long resourcereward) {
		this->hitpoint = hitpoint;
		this->movespeed = movespeed;
		this->attackpower = attackpower;
		this->resourcereward = resourcereward;
		this->movecount = 0;
	}
	virtual ~EnemyBase() = 0;

	virtual void move() = 0;
	bool isAlive() const { return hitpoint > 0; }

	long long getHitPoint() { return this->hitpoint; }
	Vector2D getPosition() const { return this->position; }

	void setHitPoint(double hitpoint) { this->hitpoint = hitpoint; }

protected:
	long long hitpoint;
	double movespeed;
	long attackpower;
	long long resourcereward;
	Vector2D position;
	double movecount;
};
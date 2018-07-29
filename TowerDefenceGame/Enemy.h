#pragma once

#include "Vector2D.h"
#include "DxLib.h"

#include <vector>
#include <math.h>

// for floating point arithmetic error
#define EPSILON 0.0001

class EnemyBase {
public:
	EnemyBase(double hitpoint, int movespeed, long attackpower, long long resourcereward) {
		this->hitpoint = hitpoint;
		this->movespeed = movespeed;
		this->attackpower = attackpower;
		this->resourcereward = resourcereward;
		this->currentpoint = 0;
		this->angle = 0;
		this->knockback = 0;
	}
	virtual ~EnemyBase() = 0;

	virtual void move(std::vector<Vector2D> &vpath) = 0;
	bool loadTexture(const char *filename);
	bool isAlive() const { return hitpoint > 0; }

	double getHitpoint() const			{ return this->hitpoint; }
	double getMovespeed() const			{ return this->movespeed; }
	long getAttackpower() const			{ return this->attackpower; }
	long long getResourcereward() const { return this->resourcereward; }
	Vector2D getPosition() const		{ return this->position; }
	double getAngle() const				{ return this->angle; }
	double getKnockback()const			{ return this->knockback; }

	void setHitpoint(double hitpoint)		{ this->hitpoint = hitpoint; }
	void setMovespeed(double movespeed)		{ this->movespeed = movespeed; }
	void setPosition(Vector2D &position)	{ this->position = position; }
	void setAngle(double angle)				{ this->angle = angle; }

	void setKnockback(double value)			{ this->knockback = knockback; }

protected:
	double hitpoint;
	double movespeed;
	long attackpower;
	long long resourcereward;
	Vector2D position;

	double angle;
	int currentpoint;
	double knockback;

	int texturehandle;
};


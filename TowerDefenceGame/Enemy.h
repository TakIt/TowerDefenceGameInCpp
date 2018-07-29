#pragma once

#include "Vector2D.h"

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
	bool isAlive() const { return hitpoint > 0; }

	double getHitpoint() const { return this->hitpoint; }
	double getMovespeed() const { return this->movespeed; }
	long getAttackpower() const { return this->attackpower; }
	long long getResourcereward() const { return this->resourcereward; }
	Vector2D getPosition() const { return this->position; }
	double getAngle() const { return this->angle; }
	

	void setHitpoint(double hitpoint) { this->hitpoint = hitpoint; }
	void setMovespeed(double movespeed) { this->movespeed = movespeed; }
	void setPosition(Vector2D &position) { this->position = position; }
	void setAngle(double angle) { this->angle = angle; }

	void takenKnockback(double value) {
		this->knockback += value;
	}

protected:
	double hitpoint;
	double movespeed;
	long attackpower;
	long long resourcereward;
	Vector2D position;

	double angle;
	int currentpoint;
	double knockback;
};


class NormalEnemy : EnemyBase {
public:
	NormalEnemy(double hitpoint, int movespeed, long attackpower, long long resourcereward) : EnemyBase(hitpoint, movespeed, attackpower, resourcereward) {
		
	}
	~NormalEnemy() {}

	void move(std::vector<Vector2D> &vpath) override {
		Vector2D nextpos;
		double nextangle;

		// taken knockback
		while (this->knockback > 0) {
			nextangle = this->getPosition().getAngleTo(vpath[currentpoint]);
			nextpos.setX(nextpos.getX() + this->knockback * cos(nextangle));
			nextpos.setY(nextpos.getY() + this->knockback * sin(nextangle));
			nextangle = nextpos.getAngleTo(vpath[currentpoint]);

			// if the position will behind start position
			if (currentpoint == 0 && fabs((this->position.getAngleTo(vpath[currentpoint]) - nextangle)) > EPSILON) {
				this->position = vpath[0];
				knockback = 0;
			}

			// if the angle to the target is different before and after the movement 
			if (fabs((this->position.getAngleTo(vpath[currentpoint]) - nextangle)) > EPSILON) {
				this->position = vpath[currentpoint];
				this->knockback -= this->position.getAbsTo(vpath[currentpoint]);
				currentpoint--;
			}
			else {
				this->position.setX(this->position.getX() + this->knockback * cos(nextangle));
				this->position.setY(this->position.getY() + this->knockback * sin(nextangle));
				this->knockback = 0;
				break;
			}
		}

		double movecount = this->movespeed;

		// move forward
		while (movecount > 0) {
			nextangle = this->getPosition().getAngleTo(vpath[currentpoint+1]);
			nextpos.setX(nextpos.getX() + movecount * cos(nextangle));
			nextpos.setY(nextpos.getY() + movecount * sin(nextangle));
			nextangle = nextpos.getAngleTo(vpath[currentpoint+1]);

			// if the position will over the start position
			if (currentpoint == vpath.size() - 1 && fabs((this->position.getAngleTo(vpath[currentpoint+1]) - nextangle)) > EPSILON) {
				// take damage to base
				write
			}

			// if the angle to the target is different before and after the movement 
			if (fabs((this->position.getAngleTo(vpath[currentpoint+1]) - nextangle)) > EPSILON) {
				this->position = vpath[currentpoint+1];
				movecount -= this->position.getAbsTo(vpath[currentpoint+1]);
				currentpoint++;
			}
			else {
				this->position.setX(this->position.getX() + movecount * cos(nextangle));
				this->position.setY(this->position.getY() + movecount * sin(nextangle));
				movecount = 0;
				break;
			}
		}
	}


protected:


};
#pragma once

#include "Vector2D.h"

class Turret {
public:
	Turret() {}
	virtual ~Turret() {}

	virtual void attack();

private:
	double attackpower;		// UŒ‚—Í
	double firerate;		// UŒ‚‘¬“x
	double attackrange;		// UŒ‚”ÍˆÍ

	Vector2D position;		// ‰æ–Êã‚ÌˆÊ’u
};
#pragma once

#include "Vector2D.h"

class Turret {
public:
	Turret() {}
	virtual ~Turret() {}

	virtual void attack();

private:
	double attackpower;
	double firerate;
	double attackrange;

	Vector2D position;
};
#pragma once

#include <math.h>

/// <summary>
/// Plane coordinates
/// </summary>
class Vector2D final {
public:
	Vector2D() {}
	Vector2D(double x,double y) {
		this->x = x;
		this->y = y;
	}
	~Vector2D() {}

	double getX() const { return x; }
	double getY() const { return y; }
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }

	double getAbs() const { return sqrt(pow(x, 2) + pow(y, 2)); }
	double getAngleTo(const Vector2D &target) const {
		if (target.x == 0 && target.y == 0) return 0;
		return atan2(target.y, target.x);
	}

private:
	double x;
	double y;

};

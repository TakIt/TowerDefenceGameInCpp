#pragma once

#include <math.h>

/// <summary>
/// Plane coordinates
/// </summary>
class Vector2D final {
public:
	Vector2D() {
		this->x = 0;
		this->y = 0;
	}
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
	double getAbsTo(const Vector2D &target) const { return sqrt(pow(this->x - target.x, 2) + pow(this->y - target.y, 2)); }
	double getAngleTo(const Vector2D &target) const {
		if (target.x == 0 && target.y == 0) return 0;
		return atan2(target.y, target.x);
	}

	Vector2D operator+(const Vector2D &obj) const {
		return Vector2D(this->x + obj.x , this->y + obj.y);
	}
	Vector2D operator+=(const Vector2D &obj) {
		return Vector2D(this->x += obj.x, this->y += obj.y);
	}
	Vector2D operator-(const Vector2D &obj) const {
		return Vector2D(this->x - obj.x, this->y - obj.y);
	}
	Vector2D operator-=(const Vector2D &obj) {
		return Vector2D(this->x -= obj.x, this->y -= obj.y);
	}
	Vector2D operator*(const double num) const {
		return Vector2D(this->x * num, this->y * num);
	}
	Vector2D operator*=(const double num) {
		return Vector2D(this->x *= num, this->y *= num);
	}
	Vector2D operator/(const double num) const {
		return Vector2D(this->x / num, this->y / num);
	}
	Vector2D operator/=(const double num) {
		return Vector2D(this->x /= num, this->y /= num);
	}

private:
	double x;
	double y;

};

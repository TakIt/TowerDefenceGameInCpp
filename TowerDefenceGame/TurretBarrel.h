#pragma once

#include "DxLib.h"
#include "Vector2D.h"

class TurretBarrel {
public:
	TurretBarrel() {
		
	}
	~TurretBarrel() {
		
	}

	bool loadTexture(const char *filename) {
		if((this->texturehandle = LoadGraph(filename)) == -1)return false;
		return true;
	}
	bool deleteTexture() {
		if((DeleteGraph(this->texturehandle)) == -1)return false;
		return true;
	}

	double getAngle() { return this->angle; }
	Vector2D getPosition() { return this->position; }
	void setAngle(double angle) { this->angle = angle; }
	void setPosition(Vector2D position) { this->position = position; }

private:
	double angle;
	Vector2D position;
	int texturehandle;
};
#include "Mouse.h"

#include "Vector2D.h"
#include "DxLib.h"


Mouse::Mouse() {
}


Mouse::~Mouse() {
}




void Mouse::update() {
	int x, y;
	GetMouseInputLog2(&this->bind, &x, &y, &this->log);
	this->position.setX(x), this->position.setY(y);
}

Vector2D Mouse::getPosition() const {
	return this->position;
}


int Mouse::getBind() const {
	return this->bind;
}


int Mouse::getLog() const {
	return this->log;
}

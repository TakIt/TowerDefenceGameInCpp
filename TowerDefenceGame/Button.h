#pragma once

#include "DxLib.h"
#include "Texture.h"

#include <string>

class Button {
public:
	Button(int x, int y) {
		this->x = x;
		this->y = y;
		wasclicked = false;
		isclicked = false;
	}
	~Button() {}

	void draw();
	void update();
	bool isClicked();
	bool init(Texture *texture, std::string filename);

protected:
	int x, y;
	int sx, sy;
	bool isclicked;
	bool wasclicked;
	Texture *texture;
	std::string filename;
};

void Button::draw() {
	DrawGraph(x, y, texture->getHandle(filename), FALSE);
}

bool Button::isClicked() {
	return isclicked;
}

void Button::update() {
	int x, y;
	GetMousePoint(&x, &y);

	isclicked = false;

	if (this->x < x && x < this->x + this->sx && this->y < y && y < this->y + sy) {
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0) {
			wasclicked = true;
		}
		else {
			if (wasclicked) {
				isclicked = true;
			}
			wasclicked = false;
		}
	}
	else {
		wasclicked = false;
	}
}

bool Button::init(Texture *texture, std::string filename) {
	this->texture = texture;
	this->filename = filename;
	if(texture->pool(filename) == -1)return false;
	if(GetGraphSize(texture->getHandle(filename), &sx, &sy) == -1)return false;
	return true;
}
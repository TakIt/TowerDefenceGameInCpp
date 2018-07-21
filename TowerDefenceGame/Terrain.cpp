#include "Terrain.h"

#include "DxLib.h"

bool TerrainBase::loadTexture(const char *filename) {
	int texturehandle = LoadGraph(filename);

	if (texturehandle == -1) {
		return false;
	}

	this->texturehandle = LoadGraph(filename);
	return true;
}
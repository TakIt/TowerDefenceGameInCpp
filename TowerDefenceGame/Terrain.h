#pragma once

/// <summary>
/// Terrain(map) class.
/// </summary>
class TerrainBase {
public:
	TerrainBase() {}
	virtual ~TerrainBase() = 0;

	bool canPlaceTurret() { return canplaceturret; }
	bool loadTexture(const char *filename);

protected:
	bool canplaceturret;
	int texturehandle;
};

class GlassTerrain : public TerrainBase {
public:
	GlassTerrain(bool canplaceturret) { this->canplaceturret = canplaceturret; }



private:
	// MAY : add StatusBonus for placed turret
};
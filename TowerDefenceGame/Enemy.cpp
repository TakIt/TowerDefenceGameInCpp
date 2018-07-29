#include "Enemy.h"

bool EnemyBase::loadTexture(const char *filename) {
	if ((texturehandle = LoadGraph(filename)) == -1)return false;
	return true;
}

class NormalEnemy : public EnemyBase {
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
			nextangle = this->getPosition().getAngleTo(vpath[currentpoint + 1]);
			nextpos.setX(nextpos.getX() + movecount * cos(nextangle));
			nextpos.setY(nextpos.getY() + movecount * sin(nextangle));
			nextangle = nextpos.getAngleTo(vpath[currentpoint + 1]);

			// if the position will over the start position
			if (currentpoint == vpath.size() - 1 && fabs((this->position.getAngleTo(vpath[currentpoint + 1]) - nextangle)) > EPSILON) {
				// take damage to base
				//write
			}

			// if the angle to the target is different before and after the movement 
			if (fabs((this->position.getAngleTo(vpath[currentpoint + 1]) - nextangle)) > EPSILON) {
				this->position = vpath[currentpoint + 1];
				movecount -= this->position.getAbsTo(vpath[currentpoint + 1]);
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
#include "Turret.h"

#include <vector>

bool TurretBase::canConstruct(long long resource) {
	return resource >= constructcost;
}
bool TurretBase::canUpgrade(long long resource) {
	return resource >= upgradecost;
}

void BasicTurret::attack(std::vector<EnemyBase> &targetlist) {
	int targetindex;

	// there is no enemy in stage
	if (targetlist.size() == 0)return;

	switch (this->targetpriority) {
	case ClosestTurret:
		double mindistance;
		if (targetlist.size() > 0) {
			targetindex = 0;
			mindistance = this->getPosition().getAbsTo(targetlist[0].getPosition());
		}

		for (int i = 0; i < (signed)targetlist.size(); i++) {
			// out of range
			if (this->range < targetlist[i].getPosition().getAbsTo(this->position)) {
				// there is no enemy in range
				if (i == (signed)targetlist.size() - 1)return;
				continue;
			}
			// farther than target
			else if (mindistance < this->getPosition().getAbsTo(targetlist[i].getPosition())) {
				continue;
			}
			mindistance = this->getPosition().getAbsTo(targetlist[i].getPosition());
			targetindex = i;
		}
		break;
	case FarthestTurret:
		double maxdistance;
		if (targetlist.size() > 0) {
			targetindex = 0;
			maxdistance = this->getPosition().getAbsTo(targetlist[0].getPosition());
		}

		for (int i = 0; i < (signed)targetlist.size(); i++) {
			// out of range
			if (this->range < targetlist[i].getPosition().getAbsTo(this->position)) {
				// there is no enemy in range
				if (i == (signed)targetlist.size() - 1)return;
				continue;
			}
			// closer than target
			else if (maxdistance > this->getPosition().getAbsTo(targetlist[i].getPosition())) {
				continue;
			}
			maxdistance = this->getPosition().getAbsTo(targetlist[i].getPosition());
			targetindex = i;
		}
		break;
	case ClosestBase:
		break;
	case FarthestBase:
		break;
	case LowestHealth:
		break;
	case HighestHealth:
		break;
	case Random:
		break;
	}

	/* attack */
	// set barrel angle to target
	this->turretbarrel.setAngle(this->getPosition().getAngleTo(targetlist[targetindex].getPosition()));
	// take damage
	targetlist[targetindex].setHitpoint(targetlist[targetindex].getHitpoint() - this->damage);

}


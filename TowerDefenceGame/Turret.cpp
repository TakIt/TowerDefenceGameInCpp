#include "Turret.h"


void TurretBase::attack(EnemyBase &target) {

}

bool TurretBase::canConstruct(long long resource) {
	return resource >= cost;
}
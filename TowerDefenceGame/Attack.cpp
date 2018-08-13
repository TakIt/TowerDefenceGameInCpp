#include"Attack.h"

int ClosestTurret::decisionOrder(std::vector<EnemyBase> &targetlist, TurretBase &turret)const{
	if (turret.getFireRate() > turret.getWaiting()) {
		turret.setWaiting(turret.getWaiting()+1.0);
		return -1;
	}
	if (targetlist.empty())return -1;
	double mindistancefromturret = DBL_MAX;
	int targetindex = 0;
	for (int i = 0; i < targetlist.size(); i++) {
		if (turret.getRange() < turret.getPosition().getAbsTo(targetlist[0].getPosition()))continue;
		if (turret.getPosition().getAbsTo(targetlist[i].getPosition()) < mindistancefromturret) {
			mindistancefromturret = turret.getPosition().getAbsTo(targetlist[i].getPosition());
			targetindex = i;
		}
	}
	turret.setWaiting(0.0);
	return targetindex;
}
int FarthestTurret::decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const{
	if (turret.getFireRate() > turret.getWaiting()) {
		turret.setWaiting(turret.getWaiting() + 1.0);
		return -1;
	}
	if (targetlist.empty())return -1;
	double maxdistancefromturret=0;
	int targetindex = 0;
	for (int i = 0; i < targetlist.size(); i++) {
		if (turret.getRange() < turret.getPosition().getAbsTo(targetlist[0].getPosition())) continue;
		if (turret.getPosition().getAbsTo(targetlist[i].getPosition()) > maxdistancefromturret) {
			maxdistancefromturret = turret.getPosition().getAbsTo(targetlist[i].getPosition());
			targetindex = i;
		}
	}
	turret.setWaiting(0.0);
	return targetindex;
}
int ClosestBase::decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const {
	return 0;
}
int FarthestBase::decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const {
	return 0;
}
int LowestHealth::decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const {
	if (turret.getFireRate() > turret.getWaiting()) {
		turret.setWaiting(turret.getWaiting() + 1.0);
		return -1;
	}
	if (targetlist.empty())return -1;
	double minHitPoint = DBL_MAX;
	int targetindex = 0;
	for (int i = 0; i < targetlist.size(); i++) {
		if (turret.getRange() < turret.getPosition().getAbsTo(targetlist[0].getPosition())) continue;
		if (targetlist[i].getHitpoint() < minHitPoint) {
			minHitPoint = turret.getPosition().getAbsTo(targetlist[i].getPosition());
			targetindex = i;
		}
	}
	turret.setWaiting(0.0);
	return targetindex;
}
int HighestHealth::decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const {
	if (turret.getFireRate() > turret.getWaiting()) {
		turret.setWaiting(turret.getWaiting() + 1.0);
		return -1;
	}
	if (targetlist.empty())return -1;
	double maxHitPoint = 0;
	int targetindex = 0;
	for (int i = 0; i < targetlist.size(); i++) {
		if (turret.getRange() < turret.getPosition().getAbsTo(targetlist[0].getPosition())) continue;
		if (targetlist[i].getHitpoint() > maxHitPoint) {
			maxHitPoint = turret.getPosition().getAbsTo(targetlist[i].getPosition());
			targetindex = i;
		}
	}
	turret.setWaiting(0.0);
	return targetindex;
}
int Random::decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const {
	return 0;
}

int ClosestTurretRing::decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const {
	if (turret.getFireRate() > turret.getWaiting()) {
		turret.setWaiting(turret.getWaiting() + 1.0);
		return -1;
	}
	if (targetlist.empty())return -1;
	double mindistancefromturret = DBL_MAX;
	int targetindex = 0;
	for (int i = 0; i < targetlist.size(); i++) {
		if (turret.getRange() < turret.getPosition().getAbsTo(targetlist[0].getPosition())) continue;
		if (turret.getMinRange() > turret.getPosition().getAbsTo(targetlist[0].getPosition())) continue;
		if (turret.getPosition().getAbsTo(targetlist[i].getPosition()) < mindistancefromturret) {
			mindistancefromturret = turret.getPosition().getAbsTo(targetlist[i].getPosition());
			targetindex = i;
		}
	}
	turret.setWaiting(0.0);
	return targetindex;
}
int FarthestTurretRing::decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const {
	if (turret.getFireRate() > turret.getWaiting()) {
		turret.setWaiting(turret.getWaiting() + 1.0);
		return -1;
	}
	if (targetlist.empty())return -1;
	double maxdistancefromturret = 0;
	int targetindex = 0;
	for (int i = 0; i < targetlist.size(); i++) {
		if (turret.getRange() < turret.getPosition().getAbsTo(targetlist[0].getPosition())) continue;
		if (turret.getMinRange() > turret.getPosition().getAbsTo(targetlist[0].getPosition())) continue;
		if (turret.getPosition().getAbsTo(targetlist[i].getPosition()) > maxdistancefromturret) {
			maxdistancefromturret = turret.getPosition().getAbsTo(targetlist[i].getPosition());
			targetindex = i;
		}
	}
	turret.setWaiting(0.0);
	return targetindex;
}
int ClosestBaseRing::decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const {
	return 0;
}
int FarthestBaseRing::decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const {
	return 0;
}
int LowestHealthRing::decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const {
	if (turret.getFireRate() > turret.getWaiting()) {
		turret.setWaiting(turret.getWaiting() + 1.0);
		return -1;
	}
	if (targetlist.empty())return -1;
	double minHitPoint = DBL_MAX;
	int targetindex = 0;
	for (int i = 0; i < targetlist.size(); i++) {
		if (turret.getRange() < turret.getPosition().getAbsTo(targetlist[0].getPosition())) continue;
		if (turret.getMinRange() > turret.getPosition().getAbsTo(targetlist[0].getPosition())) continue;
		if (targetlist[i].getHitpoint() < minHitPoint) {
			minHitPoint = turret.getPosition().getAbsTo(targetlist[i].getPosition());
			targetindex = i;
		}
	}
	turret.setWaiting(0.0);
	return targetindex;
}
int HighestHealthRing::decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const {
	if (turret.getFireRate() > turret.getWaiting()) {
		turret.setWaiting(turret.getWaiting() + 1.0);
		return -1;
	}
	if (targetlist.empty())return -1;
	double maxHitPoint = 0;
	int targetindex = 0;
	for (int i = 0; i < targetlist.size(); i++) {
		if (turret.getRange() < turret.getPosition().getAbsTo(targetlist[0].getPosition())) continue;
		if (turret.getMinRange() > turret.getPosition().getAbsTo(targetlist[0].getPosition())) continue;
		if (targetlist[i].getHitpoint() > maxHitPoint) {
			maxHitPoint = turret.getPosition().getAbsTo(targetlist[i].getPosition());
			targetindex = i;
		}
	}
	turret.setWaiting(0.0);
	return targetindex;
}
int RandomRing::decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const {
	return 0;
}
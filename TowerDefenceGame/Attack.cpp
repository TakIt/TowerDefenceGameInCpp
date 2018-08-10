#include"Attack.h"

int ClosestTurret::decisionOrder(std::vector<EnemyBase> &targetlist, TurretBase &turret)const{
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
	return targetindex;
}
int FarthestTurret::decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const{
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
	return targetindex;
}
int ClosestBase::decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const {
	return 0;
}
int FarthestBase::decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const {
	return 0;
}
int LowestHealth::decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const {
	return 0;
}
int HighestHealth::decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const {
	return 0;
}
int Random::decisionOrder(std::vector<EnemyBase>&targetlist, TurretBase &turret)const {
	return 0;
}

int ClosestTurretRing::decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const {
	if (targetlist.empty())return -1;
	double mindistancefromturret = DBL_MAX;
	int targetindex = 0;
	for (int i = 0; i < targetlist.size(); i++) {
		if (turret.getRange() < turret.getPosition().getAbsTo(targetlist[0].getPosition())) continue;
		if (turret.getSplashRange() > turret.getPosition().getAbsTo(targetlist[0].getPosition())) continue;
		if (turret.getPosition().getAbsTo(targetlist[i].getPosition()) < mindistancefromturret) {
			mindistancefromturret = turret.getPosition().getAbsTo(targetlist[i].getPosition());
			targetindex = i;
		}
	}
	return targetindex;
}
int FarthestTurretRing::decisionOrder(std::vector<EnemyBase>&targetlist, MortarTurret &turret)const {
	if (targetlist.empty())return -1;
	double maxdistancefromturret = 0;
	int targetindex = 0;
	for (int i = 0; i < targetlist.size(); i++) {
		if (turret.getRange() < turret.getPosition().getAbsTo(targetlist[0].getPosition())) continue;
		if (turret.getSplashRange() > turret.getPosition().getAbsTo(targetlist[0].getPosition())) continue;
		if (turret.getPosition().getAbsTo(targetlist[i].getPosition()) > maxdistancefromturret) {
			maxdistancefromturret = turret.getPosition().getAbsTo(targetlist[i].getPosition());
			targetindex = i;
		}
	}
	return targetindex;
}
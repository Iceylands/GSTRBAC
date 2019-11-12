#include <vector>
#include "STZone.h"
#include "Object.h"
#include "Activity.h"
#include "PSSOD.h"
#include "Permission.h"

Permission::Permission(std::vector<STZone>& z, Object& o, Activity& a, std::vector<PSSOD>& p, std::vector<PSSOD>& P) : zones(z), object(o), activity(a), pssod(p), Pssod(P) {
}
const PSSOD& Permission::addSoDPermission(Permission& p, STZone& z) {//function 24 
	PSSOD permission(z, this, p);
	pssod.push_back(permission);
	return permission;
}
void Permission::deleteSoDPermission(Permission& p, STZone& z) {//function 25

}
const std::vector<Permission>& Permission::getSoDPermission(STZone& z) {//function 26
	std::vector<Permission> sodPermission;
	return sodPermission;
}
const std::vector<Permission>& Permission::getPrerequisitePermissions() {
	std::vector<Permission> prerequisiteP;
	return prerequisiteP;
}
std::vector<STZone>& Permission::getPermissionZones() {
	return zones;
}
Object& Permission::getPermissionObject() {
	return object;
}
Activity& Permission::getActivity() {
	return activity;
}
std::vector<PSSOD>& Permission::getPermission1() {
	return pssod;
}
std::vector<PSSOD>& Permission::getPermission2() {
	return Pssod;
}
void Permission::enableZone(STZone& z) {
	zones.push_back(z);
}

#include "STZone.h"

using namespace std;

STZone::STZone(std::string& zName, Location& l, std::vector<UserRoleRelation>& rel, TimeInterval& in, std::vector<User>& u, std::vector<Role>& r,
	std::vector<Permission>& perm, std::vector<Object>& o, std::vector<PermissionAssignment>& permA, std::vector<SOD>& s, std::vector<PSSOD>& P,
	std::vector<RoleHierarchy>& rH) :name(zName), location(l), relations(rel), interval(in), users(u), roles(r), permissions(perm), objects(o),
	permAssig(permA), sods(s), pssod(P), rh(rH) {
}
//Get functions
const std::string& STZone::getName() const {
	return name;
}
Location& STZone::getLocation() {
	return location;
}
std::vector<UserRoleRelation>& STZone::getRelations() {
	return relations;
}
TimeInterval& STZone::getZoneIntervals() {
	return interval;
}
std::vector<User>& STZone::getUsers() {
	return users;
}
std::vector<Role>& STZone::getRoles() {
	return roles;
}
std::vector<Permission>& STZone::getPermissions() {
	return permissions;
}
std::vector<Object>& STZone::getObjects() {
	return objects;
}
std::vector<PermissionAssignment>& STZone::getPermAssign() {
	return permAssig;
}
std::vector<SOD>& STZone::getSOD() {
	return sods;
}
std::vector<PSSOD>& STZone::getPSSOD() {
	return pssod;
}
std::vector<RoleHierarchy>& STZone::getRH() {
	return rh;
}
#include <vector>
#include "SystemManager.h"
class Role;
class RoleHierarchy;
class TimeInterval;
class Location;
class User;
class Permission;
class PSSOD;
class SOD;
class SSOD;
class DSOD;
class STZone;
class UserRoleRelation;

using namespace std;

//empty constructor for SystemManager
SystemManager::SystemManager() {};

//get and add functions for Role objects
vector<Role*> SystemManager::getRoleCount() { return roleCount; };
void SystemManager::addRoleCount(Role* r) {
	roleCount.push_back(r);
};

//get and add functions for RoleHierarchy objects
vector<RoleHierarchy*> SystemManager::getRHCount() { return rhCount; };
void SystemManager::addRHCount(RoleHierarchy* rh) {
	rhCount.push_back(rh);
};

//get and add functions for User objects
vector<User*> SystemManager::getUserCount() { return userCount; };
void SystemManager::addUserCount(User* u) {
	userCount.push_back(u);
};

//get and add functions for TimeInterval objects
std::vector<TimeInterval*> SystemManager::getTICount() { return tiCount; };
void SystemManager::addTICount(TimeInterval* ti) {
	tiCount.push_back(ti);
};

//get and add functions for Location objects
std::vector<Location*> SystemManager::getLocationCount() { return locationCount; };
void SystemManager::addLocationCount(Location* loc) {
	locationCount.push_back(loc);
};

//get and add functions for Permission objects
vector<Permission*> SystemManager::getPermissionCount() { return permissionCount; };
void SystemManager::addPermissionCount(Permission* p) {
	permissionCount.push_back(p);
};

//get and add functions for PSSOD objects
vector<PSSOD*> SystemManager::getpssodCount() { return pssodCount; };
void SystemManager::addpssodCount(PSSOD* pssod) {
	pssodCount.push_back(pssod);
};

//get and add functions for SOD objects
vector<SOD*> SystemManager::getSODCount() { return sodCount; };
void SystemManager::addSODCount(SOD* sod) {
	sodCount.push_back(sod);
};

//get and add functions for SSOD objects
vector<SSOD*> SystemManager::getSSODCount() { return ssodCount; };
void SystemManager::addSSODCount(SSOD* ssod) {
	ssodCount.push_back(ssod);
};

//get and add functions for DSOD objects
vector<DSOD*> SystemManager::getDSODCount() { return dsodCount; };
void SystemManager::addDSODCount(DSOD* dsod) {
	dsodCount.push_back(dsod);
};

//get and add functions for STZone objects
vector<STZone*> SystemManager::getZoneCount() { return zoneCount; };
void SystemManager::addZoneCount(STZone* z) {
	zoneCount.push_back(z);
};

//get and add functions for UserRoleRelation objects
vector<UserRoleRelation*> SystemManager::getURRCount() { return urrCount; };
void SystemManager::addURRCount(UserRoleRelation* urr) {
	urrCount.push_back(urr);
};


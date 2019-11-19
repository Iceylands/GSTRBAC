//created SystemManager to keep track of instantiated objects (Marshal 11-16-19)
//when objects are created, pointers are made here to keep track of them
#include <vector>
class Role;
class RoleHierarchy;
class User;
class TimeInterval;
class Location;
class Permission;
class PSSOD;
class SOD;
class SSOD;
class DSOD;
class STZone;
class UserRoleRelation;

class SystemManager {
public:
	//empty constructor for SystemManager
	SystemManager();
	
	//get and add functions for Role objects
	std::vector<Role*> getRoleCount();
	void addRoleCount(Role*);

	//get and add functions for RoleHierarchy objects
	std::vector<RoleHierarchy*> getRHCount();
	void addRHCount(RoleHierarchy*);

	//get and add functions for User objects
	std::vector<User*> getUserCount();
	void addUserCount(User*);

	//get and add functions for TimeInterval objects
	std::vector<TimeInterval*> getTICount();
	void addTICount(TimeInterval*);

	//get and add functions for Location objects
	std::vector<Location*> getLocationCount();
	void addLocationCount(Location*);

	//get and add functions for Permission objects
	std::vector<Permission*> getPermissionCount();
	void addPermissionCount(Permission*);

	//get and add functions for PSSOD objects
	std::vector<PSSOD*> getpssodCount();
	void addpssodCount(PSSOD*);

	//get and add functions for SOD objects
	std::vector<SOD*> getSODCount();
	void addSODCount(SOD*);

	//get and add functions for SSOD objects
	std::vector<SSOD*> getSSODCount();
	void addSSODCount(SSOD*);

	//get and add functions for DSOD objects
	std::vector<DSOD*> getDSODCount();
	void addDSODCount(DSOD*);

	//get and add functions for STZone objects
	std::vector<STZone*> getZoneCount();
	void addZoneCount(STZone*);

	//get and add functions for UserRoleRelation objects
	std::vector<UserRoleRelation*> getURRCount();
	void addURRCount(UserRoleRelation*);

private:
	std::vector<Role*> roleCount;
	std::vector<RoleHierarchy*> rhCount;
	std::vector<User*> userCount;
	std::vector<TimeInterval*> tiCount;
	std::vector<Location*> locationCount;
	std::vector<Permission*> permissionCount;
	std::vector<PSSOD*> pssodCount;
	std::vector<SOD*> sodCount;
	std::vector<SSOD*> ssodCount;
	std::vector<DSOD*> dsodCount;
	std::vector<STZone*> zoneCount;
	std::vector<UserRoleRelation*> urrCount;
};
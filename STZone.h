//formalizes time and location into zones
// known values currentzone, zone, rzone, pzones, ozones

#ifndef STZONE_H
#define STZONE_H
//#include "UserRoleRelation.h" //causes multiple errors
class RoleHierarchy;
class PSSOD;
class SOD;
class PermissionAssignment;
class Object;
class Permission;
class Role;
class Location;
class UserRoleRelation;
class TimeInterval;
class User;


#include <vector>
class STZone {
public:
	STZone(std::string&, Location&, std::vector<UserRoleRelation>&, TimeInterval&, std::vector<User>&, std::vector<Role>&,
		std::vector<Permission>&, std::vector<Object>&, std::vector<PermissionAssignment>&, std::vector<SOD>&, std::vector<PSSOD>&,
		std::vector<RoleHierarchy>&);

	//Get functions
	const std::string& getName() const;
	 Location& getLocation();
	 std::vector<UserRoleRelation>& getRelations();
	 TimeInterval& getZoneIntervals();
	 std::vector<User>& getUsers();
	 std::vector<Role>& getRoles();
	 std::vector<Permission>& getPermissions();
	 std::vector<Object>& getObjects();
	 std::vector<PermissionAssignment>& getPermAssign();
	 std::vector<SOD>& getSOD();
	 std::vector<PSSOD>& getPSSOD();
	 std::vector<RoleHierarchy>& getRH();
private:
	Location& location;//generates an error			ZoneLocation aggregation
	std::vector<UserRoleRelation>& relations;//causes multipe errors
	TimeInterval& interval;//ZoneTimeInterval aggregation
	std::vector<User>& users;//UserZone association
	std::vector<Role>& roles;//RoleZone
	std::vector<Permission>& permissions;//PermissionZone association
	std::vector<Object>& objects;//ObjectZone association
	std::vector<PermissionAssignment>& permAssig;//RolePermZone association
	std::vector<SOD>& sods;//SODZone association
	std::vector<PSSOD>& pssod;//PSSODZone association
	std::vector<RoleHierarchy>& rh;//RHZone association
	std::string name;
};

#endif //
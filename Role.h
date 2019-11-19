/*Update Notes:
1- Included the include guard (Mustafa 2-5-19)
*/

/*used to create the public functions inheritsAH, getAuthorizedPermissions, getAHJuniorRoles, getAllAHInheritedRoles,AddAHJuniorRole
creates secondRole, firstRole, juniorRole, seniorRole
takes in rzones, pemAssig, relations, RH, SOD, sod*/

#ifndef ROLE_H
#define ROLE_H
#include <typeinfo>
#include "A_Hierarchy.h"
#include "I_Hierarchy.h"
#include "SSOD.h"
#include "DSOD.h"
#include "PermissionAssignment.h"
#include "Permission.h"
class SOD;
class RoleHierarchy;
class STZone;
class UserRoleRelation;
/*
std::string name;
std::vector<UserRoleRelation>& relations;//  URRRole association
std::vector<STZone>& rzones;//RoleZone association

std::vector<RoleHierarchy>& RH;//RH1Role association
std::vector<RoleHierarchy>& rh;//RH2Role association
std::vector<SOD>& sods;//SOD1&2Role association*/
#include <vector>
class Role {
public:
	Role(std::string n, std::vector<UserRoleRelation>& r, std::vector<STZone>& rz, std::vector<RoleHierarchy>& R,
		std::vector<RoleHierarchy>& rhs, std::vector<SOD>& s, const std::vector<PermissionAssignment*>& perm);

	//A_Hierarchy additions and deletion
	const A_Hierarchy& addAHJuniorRole(Role& r, STZone& z);

	void deleteAHJuniorRole(Role& r, STZone& z);

	//I_Hierarchy addition and deletion
	const I_Hierarchy& addIHJuniorRole(Role& r, STZone& z);

	void deleteIHJuniorRole(Role& r, STZone& z);

	//SSOD addition and deletion functions
	const SSOD& addSSoDRole(Role& r, STZone& z);

	void deleteSSoDRole(Role& r, STZone& z);

	//DSOD addition and deletion funtions
	const DSOD& addDSoDRole(Role& r, STZone& z);

	void deleteDSoDRole(Role& r, STZone& z);

	//Permission Assignment additions and deletion funtions
	const PermissionAssignment* assignPermission(Permission& p, STZone& z);

	void deassignPermission(Permission& p, STZone& z);

	//get SSOD Roles
	const std::vector<Role>& getSSoDRoles(STZone& z);

	//get DSOD Role function
	const std::vector<Role>& getDSoDRoles(STZone& z);

	//get Role functions
	const std::vector<Role>& getJuniorRoles(STZone& z);

	const std::vector<Role>& getAHJuniorRoles(STZone& z);

	const std::vector<Role>& getIHJuniorRoles(STZone& z);

	const std::vector<Role>& getPrerequisiteRoles();

	//two additional functions
	// 1- addPrerequisiteRole( role)
	// 2- removePrerequisiteRole(Role) 
	void addPrerequisiteRole(Role& r);

	void removePrerequisiteRole(Role& r);

	//	void addRequistorRole(Role& r) {}

	const bool inherits(Role& r, STZone& z);

	const bool inheritsAH(Role& r, STZone& z);

	const bool inheritsIH(Role& r, STZone& z);

	const std::vector<Role>& getAllAHInheritedRoles(STZone& z);

	const std::vector<Role>& getAllIHInheritedRoles(STZone& z);

	const std::vector<Permission>& getAssignedPermissions(STZone& z);

	const std::vector<Permission>& getAuthorizedPermissions(STZone& z);


	//set and get functions for the role name
	void setName(std::string given);

	const std::string& getName() const;

	void enableZone(const STZone& zone);

	const std::vector<STZone>& getEnabledZone() const;

	void getZoneName();

	void disableZone(const STZone& zone);

private:
	std::string name;
	std::vector<UserRoleRelation>& relations;//  URRRole association
	std::vector<STZone> rzones;//RoleZone association
	std::vector<RoleHierarchy>& juniorRH;//RH1Role association
	std::vector<RoleHierarchy>& seniorRH;//RH2Role association
	std::vector<SOD>& sods;//SOD1&2Role association
	std::vector<PermissionAssignment*> permAssig;//PerassToRole association
												 // need a vector for prerequisit roles and requistorRoles 
	std::vector<Role> prerequisitRoles;
	std::vector<Role> requistorRoles;

	enum RHTYPE { A_HIERARCHY = 1, I_HIERARCHY };

	RoleHierarchy * createRoleHierarchy(int rhType, Role& r, STZone& z);

	enum SODTYPE { Ssod = 1, Dsod };
	SOD * createSOD(int sodType, Role& r, STZone& z);
};


#endif // !
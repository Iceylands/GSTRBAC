/*Update Notes:
1- Included the include guard (Mustafa 2-5-19)
*/

/*used to create the public functions inheritsAH, getAuthorizedPermissions, getAHJuniorRoles, getAllAHInheritedRoles,AddAHJuniorRole
creates secondRole, firstRole, juniorRole, seniorRole
takes in rzones, pemAssig, relations, RH, SOD, sod*/

#ifndef ROLE_H
#define ROLE_H
#include<vector>
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
	Role(std::string , std::vector<UserRoleRelation>& , std::vector<STZone>& , std::vector<RoleHierarchy>& ,
		std::vector<RoleHierarchy>& , std::vector<SOD>& , const std::vector<PermissionAssignment*>& );
	//A_Hierarchy additions and deletion
	const A_Hierarchy& addAHJuniorRole(Role& , STZone& );
	void deleteAHJuniorRole(Role&, STZone&);
	//I_Hierarchy addition and deletion
	const I_Hierarchy& addIHJuniorRole(Role&, STZone& );
	void deleteIHJuniorRole(Role& , STZone& );
	//SSOD addition and deletion functions
	const SSOD& addSSoDRole(Role& , STZone&);
	void deleteSSoDRole(Role& , STZone& );
	//DSOD addition and deletion funtions
	const DSOD& addDSoDRole(Role& , STZone& );
	void deleteDSoDRole(Role&, STZone& );
	//Permission Assignment additions and deletion funtions
	const PermissionAssignment* assignPermission(Permission& , STZone& );
	void deassignPermission(Permission& , STZone& );
	//get SSOD Roles
	const std::vector<Role>& getSSoDRoles(STZone& );
	const std::vector<Role>& getDSoDRoles(STZone&);
	//get Role functions
	const std::vector<Role>& getJuniorRoles(STZone&);
	const std::vector<Role>& getAHJuniorRoles(STZone&);
	const std::vector<Role>& getIHJuniorRoles(STZone&);
	const std::vector<Role>& getPrerequisiteRoles();
	void addPrerequisiteRole(Role&);
	void removePrerequisiteRole(Role&);
	const bool inherits(Role&, STZone&);
	const bool inheritsAH(Role&, STZone& );
	const bool inheritsIH(Role& , STZone& );
	const std::vector<Role>& getAllAHInheritedRoles(STZone& );
	const std::vector<Role>& getAllIHInheritedRoles(STZone& );
	const std::vector<Permission>& getAssignedPermissions(STZone& );
	const std::vector<Permission>& getAuthorizedPermissions(STZone& );
	//set and get functions for the role name
	void setName(std::string);
	const std::string& getName() const;
	void enableZone(const STZone& );
	const std::vector<STZone>& getEnabledZone() const;
	void getZoneName();

	void disableZone(const STZone&);

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

	RoleHierarchy* createRoleHierarchy(int rhType, Role& r, STZone& z) {
		RoleHierarchy* rhPtr;

		switch (rhType) {
		case A_HIERARCHY:
			rhPtr = new A_Hierarchy(z, r, this);
			break;
		case I_HIERARCHY:
			rhPtr = new I_Hierarchy(z, r, this);
			break;
		default:
			rhPtr = NULL;
			break;
		}
		return rhPtr;
	}

	enum SODTYPE { Ssod = 1, Dsod };
	SOD* createSOD(int sodType, Role& r, STZone& z) {
		SOD* sodPtr;

		switch (sodType) {
		case SODTYPE::Ssod:
			sodPtr = new SSOD(z, r, this);
			break;
		case SODTYPE::Dsod:
			sodPtr = new DSOD(z, r, this);
			break;
		default:
			sodPtr = NULL;
			break;
		}
		return sodPtr;
	}
};


#endif // !
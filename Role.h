/*Update Notes:
1- Included the include guard (Mustafa 2-5-19)
*/

/*used to create the public functions inheritsAH, getAuthorizedPermissions, getAHJuniorRoles, getAllAHInheritedRoles,AddAHJuniorRole
creates secondRole, firstRole, juniorRole, seniorRole
takes in rzones, pemAssig, relations, RH, SOD, sod*/

#ifndef ROLE_H
#define ROLE_H
#include <iostream>
#include <vector>
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
		std::vector<RoleHierarchy>& rhs, std::vector<SOD>& s, const std::vector<PermissionAssignment*>& perm) : name(n), relations(r), rzones(rz), juniorRH(R), seniorRH(rhs), sods(s), permAssig(perm) {

	}
	//A_Hierarchy additions and deletion
	const A_Hierarchy& addAHJuniorRole(Role& r, STZone& z) {// function 1
		RoleHierarchy *rhPtr;
		rhPtr = createRoleHierarchy(A_HIERARCHY, r, z);
		juniorRH.push_back(*rhPtr);

		A_Hierarchy ahObj(z, r, this);
		return ahObj;
	}
	void deleteAHJuniorRole(Role& r, STZone& z) {//function 2


	}
	//I_Hierarchy addition and deletion
	const I_Hierarchy& addIHJuniorRole(Role& r, STZone& z) {// function 3
		RoleHierarchy *rhPtr;
		rhPtr = createRoleHierarchy(I_HIERARCHY, r, z);
		juniorRH.push_back(*rhPtr);

		I_Hierarchy ihObj{ z,r,this };
		return ihObj;
	}
	void deleteIHJuniorRole(Role& r, STZone& z) { // function 4

	}
	//SSOD addition and deletion functions
	const SSOD& addSSoDRole(Role& r, STZone& z) {// function 5
		SOD *sodPtr;
		sodPtr = createSOD(SODTYPE::Ssod, r, z);
		sods.push_back(*sodPtr);

		SSOD ssodObj{ z,r,this };
		return ssodObj;
	}
	void deleteSSoDRole(Role& r, STZone& z) {//function 6

	}
	//DSOD addition and deletion funtions
	const DSOD& addDSoDRole(Role& r, STZone& z) { //function 7
		SOD *sodPtr;
		sodPtr = createSOD(SODTYPE::Dsod, r, z);
		sods.push_back(*sodPtr);

		DSOD dsodOjb{ z,r,this };
		return dsodOjb;
	}
	void deleteDSoDRole(Role& r, STZone& z) {// function 8

	}
	//Permission Assignment additions and deletion funtions
	const PermissionAssignment* assignPermission(Permission& p, STZone& z) {//function 9 
		PermissionAssignment *paPtr;
		paPtr = new PermissionAssignment(z, p, this);
		permAssig.push_back(paPtr);
		return paPtr;
	}
	void deassignPermission(Permission& p, STZone& z) {//function 10

	}
	//get SSOD Roles
	const std::vector<Role>& getSSoDRoles(STZone& z) {// function 11
		std::vector<Role> ssodRole;

		for (SOD sod : sods) {
			if (typeid(sod) == typeid(SSOD)) {
				STZone zone = sod.getZone();
				if (zone.getName() == z.getName()) {
					ssodRole.push_back(sod.getFirstRole());
				}
			}
		}

		return ssodRole;
	}
	//get DSOD Role function
	const std::vector<Role>& getDSoDRoles(STZone& z) {//function 12
		std::vector<Role> dsodRole;

		for (SOD sod : sods) {
			if (typeid(sod) == typeid(DSOD)) {
				STZone zone = sod.getZone();
				if (zone.getName() == z.getName()) {
					dsodRole.push_back(sod.getFirstRole());
				}
			}
		}

		return dsodRole;
	}
	//get Role functions
	const std::vector<Role>& getJuniorRoles(STZone& z) {//function 13
		std::vector<Role> juniorRoles;

		for (RoleHierarchy roleHierarchy : juniorRH) {
			STZone zone = roleHierarchy.getZone();
			if (zone.getName() == z.getName()) {
				juniorRoles.push_back(roleHierarchy.getJRole());
			}
		}

		return juniorRoles;
	}
	const std::vector<Role>& getAHJuniorRoles(STZone& z) {//function 14
		std::vector<Role> ahjRoles;

		for (RoleHierarchy roleHierarchy : juniorRH) {
			if (typeid(roleHierarchy) == typeid(A_HIERARCHY)) {
				STZone zone = roleHierarchy.getZone();
				if (zone.getName() == z.getName()) {
					ahjRoles.push_back(roleHierarchy.getJRole());
				}
			}
		}

		return ahjRoles;
	}
	const std::vector<Role>& getIHJuniorRoles(STZone& z) {//function 15
		std::vector<Role> ihjRoles;

		for (RoleHierarchy roleHierarchy : juniorRH) {
			if (typeid(roleHierarchy) == typeid(I_HIERARCHY)) {
				STZone zone = roleHierarchy.getZone();
				if (zone.getName() == z.getName()) {
					ihjRoles.push_back(roleHierarchy.getJRole());
				}
			}
		}

		return ihjRoles;
	}
	const std::vector<Role>& getPrerequisiteRoles() {// functions 16
		std::vector<Role> preRoles;
		return preRoles;
	}

	//two additional functions
	// 1- addPrerequisiteRole( role)
	// 2- removePrerequisiteRole(Role) 
	void addPrerequisiteRole(Role& r) {
		prerequisitRoles.push_back(r);
	}
	void removePrerequisiteRole(Role& r) {

	}
	//	void addRequistorRole(Role& r) {}

	const bool inherits(Role& r, STZone& z) {// function 17 tested and functioning, tested with both true and false
		std::vector<Role> juniorRoles = getJuniorRoles(z);

		for (Role role : juniorRoles) {
			std::vector<Role> temp;
			if (r.getName() == role.getName()) {
				temp.push_back(role);
				return true;
			}
		}
		// if r is in getJuniorRoles(STZone& z)
		// return true 
		// else return false 
		return false;

	}
	const bool inheritsAH(Role& r, STZone& z) {// function 18 tested and functioning , tested with both true and false
		std::vector<Role> juniorRoles = getAHJuniorRoles(z);

		for (Role role : juniorRoles) {
			std::vector<Role> temp;
			if (r.getName() == role.getName()) {
				temp.push_back(role);
				return true;
			}
		}

		return false;
	}
	const bool inheritsIH(Role& r, STZone& z) {// functioning and tested with both true and false  19
		std::vector<Role> juniorRoles = getIHJuniorRoles(z);

		for (Role role : juniorRoles) {
			std::vector<Role> temp;
			if (r.getName() == role.getName()) {
				temp.push_back(role);
				return true;
			}
		}

		return false;
	}
	const std::vector<Role>& getAllAHInheritedRoles(STZone& z) {// function 20 
		std::vector<Role> allAHIRoles;
		return allAHIRoles;
	}
	const std::vector<Role>& getAllIHInheritedRoles(STZone& z) {//function 21
		std::vector<Role> allIHIRoles;
		return allIHIRoles;
	}
	const std::vector<Permission>& getAssignedPermissions(STZone& z) {//function 22
		std::vector<Permission> assignedP;
		return assignedP;
	}
	const std::vector<Permission>& getAuthorizedPermissions(STZone& z) {//function 23
		std::vector<Permission> authorizedP;
		return authorizedP;
	}
	//set and get functions for the role name
	void setName(std::string given) {
		name = given;
	}
	const std::string& getName() const {
		return name;
	}
	void enableZone(const STZone& zone) {
		rzones.push_back(zone);
	}
	const std::vector<STZone>& getEnabledZone() const {
		return rzones;
	}

	void getZoneName() {
		for (auto zones : rzones) {
			std::cout << zones.getName() << "\n";
		}
	}

	void disableZone(const STZone& zone) {
		std::size_t size;
		static std::vector<STZone> temp{};

		if (rzones.back().getName() == zone.getName()) {
			rzones.pop_back();
		}
		else {
			temp.push_back(rzones.back());
			rzones.pop_back();
			disableZone(zone);
		}

		rzones.clear();
		//rzones = temp;

		for (auto zone : temp) {
			rzones.push_back(zone);
		}

	}

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

	RoleHierarchy * createRoleHierarchy(int rhType, Role& r, STZone& z) {
		RoleHierarchy *rhPtr;

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
	SOD * createSOD(int sodType, Role& r, STZone& z) {
		SOD *sodPtr;

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
#include <iostream>
#include "Role.h"

Role::Role(std::string n, std::vector<UserRoleRelation>& r, std::vector<STZone>& rz, std::vector<RoleHierarchy>& R,
	std::vector<RoleHierarchy>& rhs, std::vector<SOD>& s, const std::vector<PermissionAssignment*>& perm) : name(n), relations(r), rzones(rz), juniorRH(R), seniorRH(rhs), sods(s), permAssig(perm) {

}
//A_Hierarchy additions and deletion
const A_Hierarchy& Role::addAHJuniorRole(Role& r, STZone& z) {// function 1
	RoleHierarchy* rhPtr;
	rhPtr = createRoleHierarchy(A_HIERARCHY, r, z);
	juniorRH.push_back(*rhPtr);

	A_Hierarchy ahObj(z, r, this);
	return ahObj;
}
void Role::deleteAHJuniorRole(Role& r, STZone& z) {//function 2


}
//I_Hierarchy addition and deletion
const I_Hierarchy& Role::addIHJuniorRole(Role& r, STZone& z) {// function 3
	RoleHierarchy* rhPtr;
	rhPtr = createRoleHierarchy(I_HIERARCHY, r, z);
	juniorRH.push_back(*rhPtr);

	I_Hierarchy ihObj{ z,r,this };
	return ihObj;
}
void Role::deleteIHJuniorRole(Role& r, STZone& z) { // function 4

}
//SSOD addition and deletion functions
const SSOD& Role::addSSoDRole(Role& r, STZone& z) {// function 5
	SOD* sodPtr;
	sodPtr = createSOD(SODTYPE::Ssod, r, z);
	sods.push_back(*sodPtr);

	SSOD ssodObj{ z,r,this };
	return ssodObj;
}

void Role::deleteSSoDRole(Role& r, STZone& z) {//function 6

}
//DSOD addition and deletion funtions
const DSOD& Role::addDSoDRole(Role& r, STZone& z) { //function 7
	SOD* sodPtr;
	sodPtr = createSOD(SODTYPE::Dsod, r, z);
	sods.push_back(*sodPtr);

	DSOD dsodOjb{ z,r,this };
	return dsodOjb;
}
void Role::deleteDSoDRole(Role& r, STZone& z) {// function 8

}
//Permission Assignment additions and deletion funtions
const PermissionAssignment* Role::assignPermission(Permission& p, STZone& z) {//function 9 
	PermissionAssignment* paPtr;
	paPtr = new PermissionAssignment(z, p, this);
	permAssig.push_back(paPtr);
	return paPtr;
}
void Role::deassignPermission(Permission& p, STZone& z) {//function 10

}
//get SSOD Roles
const std::vector<Role>& Role::getSSoDRoles(STZone& z) {// function 11
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
const std::vector<Role>& Role::getDSoDRoles(STZone& z) {//function 12
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
const std::vector<Role>& Role::getJuniorRoles(STZone& z) {//function 13
	std::vector<Role> juniorRoles;

	for (RoleHierarchy roleHierarchy : juniorRH) {
		STZone zone = roleHierarchy.getZone();
		if (zone.getName() == z.getName()) {
			juniorRoles.push_back(roleHierarchy.getJRole());
		}
	}

	return juniorRoles;
}
const std::vector<Role>& Role::getAHJuniorRoles(STZone& z) {//function 14
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
const std::vector<Role>& Role::getIHJuniorRoles(STZone& z) {//function 15
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
const std::vector<Role>& Role::getPrerequisiteRoles() {// functions 16
	std::vector<Role> preRoles;
	return preRoles;
}

//two additional functions
// 1- addPrerequisiteRole( role)
// 2- removePrerequisiteRole(Role) 
void Role::addPrerequisiteRole(Role& r) {
	prerequisitRoles.push_back(r);
}
void Role::removePrerequisiteRole(Role& r) {

}
//	void addRequistorRole(Role& r) {}

const bool Role::inherits(Role& r, STZone& z) {// function 17 tested and functioning, tested with both true and false
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
const bool Role::inheritsAH(Role& r, STZone& z) {// function 18 tested and functioning , tested with both true and false
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
const bool Role::inheritsIH(Role& r, STZone& z) {// functioning and tested with both true and false  19
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
const std::vector<Role>& Role::getAllAHInheritedRoles(STZone& z) {// function 20 
	std::vector<Role> allAHIRoles;
	return allAHIRoles;
}
const std::vector<Role>& Role::getAllIHInheritedRoles(STZone& z) {//function 21
	std::vector<Role> allIHIRoles;
	return allIHIRoles;
}
const std::vector<Permission>& Role::getAssignedPermissions(STZone& z) {//function 22
	std::vector<Permission> assignedP;
	return assignedP;
}
const std::vector<Permission>& Role::getAuthorizedPermissions(STZone& z) {//function 23
	std::vector<Permission> authorizedP;
	return authorizedP;
}
//set and get functions for the role name
void Role::setName(std::string given) {
	name = given;
}
const std::string& Role::getName() const {
	return name;
}
void Role::enableZone(const STZone& zone) {
	rzones.push_back(zone);
}
const std::vector<STZone>& Role::getEnabledZone() const {
	return rzones;
}

void Role::getZoneName() {
	for (auto zones : rzones) {
		std::cout << zones.getName() << "\n";
	}
}

void Role::disableZone(const STZone& zone) {
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
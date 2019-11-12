#include <iostream>
#include <vector>
#include "A_Hierarchy.h"
#include "I_Hierarchy.h"
#include "SSOD.h"
#include "DSOD.h"
#include "PermissionAssignment.h"
#include "Permission.h"
#include "Role.h"
class SOD;
class RoleHierarchy;
class STZone;
class UserRoleRelation;
#include <vector>

using namespace std;

Role::Role(string n, vector<UserRoleRelation>& r, vector<STZone>& rz, vector<RoleHierarchy>& R,
	vector<RoleHierarchy>& rhs, vector<SOD>& s, vector<PermissionAssignment>& perm) : name(n), relations(r), rzones(rz), juniorRH(R), seniorRH(rhs), sods(s), permAssig(perm) {

}
//A_Hierarchy additions and deletion
const A_Hierarchy& Role::addAHJuniorRole(Role& r, STZone& z) {// function 1
	RoleHierarchy* rhPtr;
	rhPtr = createRoleHierarchy(RHType::A_HIERARCHY, r, z);
	juniorRH.push_back(rhPtr);
}
void Role::deleteAHJuniorRole(Role& r, STZone& z) {//function 2


}
//I_Hierarchy addition and deletion
const I_Hierarchy& Role::addIHJuniorRole(Role& r, STZone& z) {// function 3
	RoleHierarchy* rhPtr;
	rhPtr = createRoleHierarchy(RHType::I_HIERARCHY, r, z);
	juniorRH.push_back(rhPtr);
}
void Role::deleteIHJuniorRole(Role& r, STZone& z) { // function 4

}
//SSOD addition and deletion functions
const SSOD& Role::addSSoDRole(Role& r, STZone& z) {// function 5
	SOD* SoDPtr;
	SoDPtr = createSoD(SoDType::SSoD, r, z);
	sods.push_back(SoDPtr);
}
void Role::deleteSSoDRole(Role& r, STZone& z) {//function 6

}
//DSOD addition and deletion funtions
const DSOD& Role::addDSoDRole(Role& r, STZone& z) { //function 7
	SOD* SoDPtr;
	SoDPtr = createSoD(SoDType::DSoD, r, z);
	sods.push_back(SoDPtr);
}
void Role::deleteDSoDRole(Role& r, STZone& z) {// function 8

}
//Permission Assignment additions and deletion funtions
const PermissionAssignment& Role::assignPermission(const Permission& p, const STZone& z) {//function 9 
	PermissionAssignment* paPtr;
	paPtr = new PermissionAssignment(p, z, this);
	permAssig.push_back(paPtr);
}
void Role::deassignPermission(Permission& p, STZone& z) {//function 10

}
//get SSOD Roles
const vector<Role>& Role::getSSoDRoles(STZone& z) {// function 11
	vector<Role> ssodRole;
	for (SOD sod : sods) {
		if (typeid(sods)==typeid(SSOD)) {
			STZone z2 = sod.getZone();
			if (z2.getName() == z.getName()) {
				vector<Role&> sodRole = sod.getInvolvedRoles();
				ssodRole.push_back(sodRole[0]);
				ssodRole.push_back(sodRole[1]);
			}
		}
		return ssodRole;
	}
}
//get DSOD Role function
const vector<Role>& Role::getDSoDRoles(STZone& z) {//function 12
	vector<Role> dsodRole;
	for (SOD sod : sods) {
		if (typeid(sods) == typeid(DSOD)) {
			STZone z2 = sod.getZone();
			if (z2.getName() == z.getName()) {
				vector<Role&> sodRole = sod.getInvolvedRoles();
				dsodRole.push_back(sodRole[0]);
				dsodRole.push_back(sodRole[1]);
			}
		}
		return dsodRole;
	}
}
//get Role functions
const vector<Role>& Role::getJuniorRoles(STZone& z) {//function 13
	vector<Role> juniorRoles;
	for (RoleHierarchy role : juniorRH) {
		juniorRoles.push_back(role.getJRole());
	}
	return juniorRoles;
}
const vector<Role>& Role::getAHJuniorRoles(STZone& z) {//function 14
	vector<Role> ahJuniorRoles;
	for (RoleHierarchy junior : juniorRH) {
		if (typeid(juniorRH) == typeid(A_Hierarchy)) {
			STZone z2 = junior.getZone();
			if (z2.getName() == z.getName()) {
				ahJuniorRoles.push_back(junior.getJRole());
			}
		}
		return ahJuniorRoles;
	}
}
const vector<Role>& Role::getIHJuniorRoles(STZone& z) {//function 15
	vector<Role> ihJuniorRoles;
	for (RoleHierarchy junior : juniorRH) {
		if (typeid(juniorRH) == typeid(I_Hierarchy)) {
			STZone z2 = junior.getZone();
			if (z2.getName() == z.getName()) {
				ihJuniorRoles.push_back(junior.getJRole());
			}
		}
		return ihJuniorRoles;
	}
}
const vector<Role>& Role::getPrerequisiteRoles() {// functions 16
	/*vector<Role> preRoles;*/
	/*return preRoles;*/
	return prerequisitRoles;
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

	// if r is in getJuniorRoles(STZone& z)
	// return true 
	// else return false 
	return true;

}
const bool Role::inheritsAH(Role& r, STZone& z) {// function 18 tested and functioning , tested with both true and false
	vector<Role> ahJuniorRoles;
	vector<Role> juniorRoles = getJuniorRoles(z);
	for (Role role : juniorRoles) {
		if (r.getName() == role.getName()) {
			ahJuniorRoles.push_back(role);
			return true;
		}
	}
}
const bool Role::inheritsIH(Role& r, STZone& z) {// functioning and tested with both true and false  19
	vector<Role> ihJuniorRoles;
	vector<Role> juniorRoles = getJuniorRoles(z);
	for (Role role : juniorRoles) {
		if (r.getName() == role.getName()) {
			ihJuniorRoles.push_back(role);
			return true;
		}
	}
}
const vector<Role>& Role::getAllAHInheritedRoles(STZone& z) {// function 20 
	vector<Role> allAHIRoles;
	return allAHIRoles;
}
const vector<Role>& Role::getAllIHInheritedRoles(STZone& z) {//function 21
	vector<Role> allIHIRoles;
	return allIHIRoles;
}
const vector<Permission>& Role::getAssignedPermissions(STZone& z) {//function 22
	vector<Permission> assignedP;
	return assignedP;
}
const vector<Permission>& Role::getAuthorizedPermissions(STZone& z) {//function 23
	vector<Permission> authorizedP;
	return authorizedP;
}
//set and get functions for the role name
void Role::setName(string given) {
	name = given;
}
const string& Role::getName() const {
	return name;
}
void Role::enableZone(const STZone& zone) {
	rzones.push_back(zone);
}
const vector<STZone>& Role::getEnabledZone() const {
	return rzones;
}

void Role::getZoneName() {
	for (auto zones : rzones) {
		cout << zones.getName() << "\n";
	}
}

void Role::disableZone(const STZone& zone) {
	size_t size;
	static vector<STZone> temp{};

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

	RoleHierarchy* Role::createRoleHierarchy(RHType, Role& r, STZone& z) {  //utility function to create new RoleHierarchy derived objects
		RoleHierarchy* rhPtr;
		switch (RHType) {
		case RHType::A_HIERARCHY:
			rhPtr = new A_Hierarchy(z, r, this);
			break;
		case RHType::I_HIERARCHY:
			rhPtr = new I_Hierarchy(z, r, this);
			break;
		}
		return rhPtr;
	}


	SOD* Role::createSoD(SoDType, Role& r, STZone& z) {  //utility function to create new SOD derived objects
		SOD* SoDPtr;
		switch (SoDType) {
		case SoDType::SSoD:
			SoDPtr = new SSOD(z, r);
			break;
		case SoDType::DSoD:
			SoDPtr = new DSOD(z, r);
			break;
		}
		return SoDPtr;
	};

};
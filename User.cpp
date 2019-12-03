/*5 - added the body to getName() funciton(Mustafa 5 - 2 - 19)
*/

#include "User.h"
#include <iostream>
#include <string>
#include "STZone.h"
#include "Role.h"
#include"UserRoleAssignment.h"
#include "UserRoleActivation.h"
#include "UserRoleRelation.h"
#include "Activity.h"
#include "Object.h"
#include <vector>

//#include "UserRoleRelation.h"
//class UserRoleRelation;

enum URRTYPE { Assignment = 1, Activation };

User::User(std::string &userName, std::vector<UserRoleRelation> &userRelations, STZone& cZone) :name(userName), relations(userRelations),
currentZone(cZone) {
}

/*	,
const std::vector<UserRoleRelation> &userRelations)
{

name{ userName };
relations{ userRelations };

}
*/
//User(const User&) = default;
//A(const A&) = default;
//User& operator=(const User&) = default;
//A& operator=(const A&) = default;


const UserRoleAssignment& User::assignRole(Role& r, STZone& z) {									//done 3/8
																								//for now, we are going to ignore the pre and post conditions of this functions
																									//User u1;
	UserRoleRelation *urrPtr;
	urrPtr = createUserRoleRelation(Assignment, r, z);
	relations.push_back(*urrPtr);

	UserRoleAssignment uraObj{ this, r,z };
	userAssignedRoles.push_back(uraObj);
	return uraObj;
}
void User::deassignRole(Role& r, STZone& z) {
	std::vector<UserRoleAssignment> temp;
	size_t size = userAssignedRoles.size();
	for (int i(0); i < size; i++) {
		if (userAssignedRoles.back().getRole().getName() == r.getName()) {
			if (userAssignedRoles.back().getZone().getName() == z.getName()) {
				userAssignedRoles.pop_back();
			}
			else {
				temp.push_back(userAssignedRoles.back());
				userAssignedRoles.pop_back();
			}
		}
		else {
			temp.push_back(userAssignedRoles.back());
			userAssignedRoles.pop_back();
		}

	}
	userAssignedRoles.clear();
	for (auto assig : temp) {
		userAssignedRoles.push_back(assig);
	}

}
const UserRoleActivation& User::activateRole(Role& r, STZone& z) {// added 02/07 and tested		//done 3/8
																  // similar to assignRole 
	UserRoleRelation *urrPtr;
	urrPtr = createUserRoleRelation(Activation, r, z);
	relations.push_back(*urrPtr);
	
	UserRoleActivation uractObj{ this, r, z };
	userActivatedRoles.push_back(uractObj);
	return uractObj;
}
void User::deactivateRole(Role& r, STZone& z) {			//added 02/07 
	std::vector<UserRoleActivation> temp;
	size_t size = userActivatedRoles.size();
	for (int i(0); i < size; i++) {
		if (userActivatedRoles.back().getRole().getName() == r.getName()) {
			if (userActivatedRoles.back().getZone().getName() == z.getName()) {
				userActivatedRoles.pop_back();
			}
			else {
				temp.push_back(userActivatedRoles.back());
				userActivatedRoles.pop_back();
			}
		}
		else {
			temp.push_back(userActivatedRoles.back());
			userActivatedRoles.pop_back();
		}

	}
	userActivatedRoles.clear();
	for (auto assig : temp) {
		userActivatedRoles.push_back(assig);
	}

}
const std::vector<Role> User::getAssignedRoles(const STZone& z) {    //added 02/07 and tested
	std::vector<Role> temp{};
	size_t size = userAssignedRoles.size();
	for (int i(0); i < size; i++) {
		if (userAssignedRoles[i].getZone().getName() == z.getName()) {
			temp.push_back(userAssignedRoles[i].getRole());
		}
	}
	return temp;
}
const std::vector<Role>& User::getActivatedRoles(const STZone& z) {
	std::vector<Role> activeRoles{};
	size_t size = userActivatedRoles.size();
	for (int i(0); i < size; i++) {
		if (userActivatedRoles[i].getZone().getName() == z.getName()) {
			activeRoles.push_back(userActivatedRoles[i].getRole());
		}
	}

	return activeRoles;
}
const std::vector<Role>& User::getAuthorizedRoles(STZone& z) {
	std::cout << "\nvector of authorized roles";
	std::vector<Role> authorizedRoles { getAssignedRoles(z) };
	std::vector<Role> juniorRole{};

	size_t size = userActivatedRoles.size();
	for (int i(0); i < size; i++) {
		size_t jsize = authorizedRoles[i].getJuniorRoles(z).size();
		for (int j(0); j < jsize; j++) {
			juniorRole.push_back(authorizedRoles[i].getJuniorRoles(z)[j]);
		}
	}
	size_t fullSize = juniorRole.size();
	for (int i(0); i < fullSize; i++) {
		authorizedRoles.push_back(juniorRole[i]);
	}
	//Algorithm:
	//authorizedRoles = getAssignedRoles(z);
	// create juniorRole vector
	// loop over authorizeRole vector
	// get their junior roles at a particular zone
	// push them to juniorRole vector
	// push juniorRoles to authorizedRoles vector
	// return authorizedRole vector

	// get all assigne roles in addition of their junior role
	// at particular zone
	// push them to the authorizedRoles vector 
	return authorizedRoles;

}

const bool User::checkAccess(Object& o, Activity& a, STZone& z) {
	std::vector<Role> activatedRoles = getActivatedRoles(z);
	std::vector<Permission> permissions = a.getPermissions();

	for (Role role : activatedRoles) {
		for (Permission perm : role.getAssignedPermissions(z)) {
			for (Permission perm2 : permissions) {
				if (perm2.getPermissionObject().getObjName() == perm.getPermissionObject().getObjName()) {
					return true;
				}
			}
		}
	}
	
	return false;

}
// You need to include the other member functions signatures here 

std::string& User::getName() const {
	return name;
}
void User::setName(std::string givenName) {
	name = givenName;
}
const STZone& User::getCurrentZone() {
	return currentZone;
}

UserRoleRelation * User::createUserRoleRelation(int urrType, Role& r, STZone& z) {
	UserRoleRelation *urrPtr;

	switch (urrType) {
	case Assignment:
		urrPtr = new UserRoleAssignment(this, r, z);
		break;
	case Activation:
		urrPtr = new UserRoleActivation(this, r, z);
		break;
	default:
		urrPtr = NULL;
		break;
	}
	return urrPtr;

}
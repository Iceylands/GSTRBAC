#include "UserRoleRelation.h"
#include "User.h"
#include "Role.h"
#include "STZone.h"
#include "UserRoleAssignment.h"

UserRoleAssignment::UserRoleAssignment(User* u, Role& r,
	STZone& z) :UserRoleRelation::UserRoleRelation(u, r, z) {

}
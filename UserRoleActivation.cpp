#include "UserRoleActivation.h"
#include"UserRoleRelation.h"

UserRoleActivation::UserRoleActivation(User* u, Role& r,
	STZone& z) :UserRoleRelation::UserRoleRelation(u, r, z)
{
}
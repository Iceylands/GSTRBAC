
#include "UserRoleRelation.h"
#include "STZone.h"

UserRoleRelation::UserRoleRelation(User* u, Role& r, STZone& z) : user(u), role(r), zone(z) {
	//user = u;
	//role = r;
	//zone = z ;
}
/*
UserRoleRelation(Role& r, //Old Constructor, Delete?
		STZone& z): role{ r }, zone{ z } {

}
*/
const User* UserRoleRelation::getUser() {
	return user;
}
const Role& UserRoleRelation::getRole() {
	return role;
}
const STZone& UserRoleRelation::getZone() {
	return zone;
}
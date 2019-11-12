
#ifndef USERROLERELATION_H
#define USERROLERELATION_H
//#include "User.h"
//#include "Role.h"
#include "STZone.h"
class User;
class Role;
class STZone;
class UserRoleRelation  {
public:
	UserRoleRelation(User* u, Role& r, STZone& z) : user( u ), role( r ), zone( z ) {
		//user = u;
		//role = r;
		//zone = z ;
	}
	/*
	UserRoleRelation(Role& r,
		 STZone& z): role{ r }, zone{ z } {

	}
	*/
	const User* getUser() const {
		return user;
	}
	const Role& getRole() const {
		return role;
	}
	const STZone& getZone() const {
		return zone;
	}
	
private:
	User* user; //URRUser association
	Role& role; //URRRole association 
	STZone& zone;
	
};
#endif
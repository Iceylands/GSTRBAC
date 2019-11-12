//1- Seperated code into two files (Miguelangel 9-17-19)
//has no prior heirarchy but is inheritated from userRoleRelation
#ifndef USERROLEACTIVATION_H
#define	USERROLEACTIVATION_H
#include"UserRoleRelation.h"
#include "STZone.h" // Added this, inheritance only works down one level Rey 9-17-19
class UserRoleActivation: public UserRoleRelation {
public:
	
	UserRoleActivation(User* u, Role& r,
		STZone& z);

private:

};
#endif
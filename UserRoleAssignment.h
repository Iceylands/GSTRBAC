/* Update notes
1- capatalized the name of the class (Mustafa 2-5-19)
2- You should create the inheritance here (Mustafa 2-5-19)
3- Included the include guard (Mustafa 2-5-19)
*/
/*has no inheritance but is the base class for userRoleRelation
*/

#ifndef USERROLEASSIGNMENT_H
#define USERROLEASSIGNMENT_H
#include "UserRoleRelation.h"
#include"User.h"
#include"Role.h"
#include"STZone.h"

class UserRoleAssignment: public UserRoleRelation {
public:
	UserRoleAssignment(User* u, Role& r,
		STZone& z) :UserRoleRelation::UserRoleRelation(u, r, z) {

	}

private:
};

#endif // !USERROLEASSIGNMENT_H
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

//Removed Include cases for user role and STZone as UserRoleRelation already initalized them before.

class UserRoleAssignment: public UserRoleRelation {
public:
	UserRoleAssignment(User* u, Role& r, STZone& z);

private:
};

#endif // !USERROLEASSIGNMENT_H
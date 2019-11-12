/* Update notes
 I capitalized the name of the class from permissionAssignment (Mustafa 2-6-19)
 */
#ifndef PERMISSIONASSIGNMENT_H
#define PERMISSIONASSIGNMENT_H
#include "Permission.h"
class STZone;
class PermissionAssignment {
public:
	PermissionAssignment(STZone&, Permission&, Role*);

	const STZone& getPAZone();

	const Permission& getPAPermission();

	Role* getPARole();

private:
	STZone& zone;
	Permission& permission;
	Role* role;
};
#endif
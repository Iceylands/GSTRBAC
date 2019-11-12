#include "STZone.h"
#include "PermissionAssignment.h"

PermissionAssignment::PermissionAssignment(STZone& z, Permission& p, Role* r) :zone(z), permission(p), role(r) {
}
const STZone& PermissionAssignment::getPAZone() {
	return zone;
}
const Permission& PermissionAssignment::getPAPermission() {
	return permission;
}
Role* PermissionAssignment::getPARole() {
	return role;
}
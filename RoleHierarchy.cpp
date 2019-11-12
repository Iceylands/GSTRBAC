
#include <iostream>
#include "RoleHierarchy.h"
#include "Role.h"
#include "STZone.h"

using namespace std;

RoleHierarchy::RoleHierarchy(STZone& z, Role& junior, Role* senior) 
	:zone(z), juniorRole(junior), seniorRole(senior) 
{

}
	
	STZone& RoleHierarchy::getZone() {
		return zone;
	}
	
	Role& RoleHierarchy::getJRole() {
		return juniorRole;
	}
	
	Role* RoleHierarchy::getSRole() {
		return seniorRole;
	}

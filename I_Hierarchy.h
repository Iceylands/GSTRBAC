#pragma once
/*
1- fixed the inheritance hierarchy structure here (Mustafa 2-5-19)
2- included the include header for roleHierarchy class, name of
the header is still to be capatilized file ne (Mustafa 2-5-19)
*/
#ifndef I_HIERARCHY_H
#define I_HIERARCHY_H
#include"RoleHierarchy.h"

class I_Hierarchy : public RoleHierarchy {
public:
	I_Hierarchy(STZone& z, Role& junior, Role* senior);

private:


};
#endif
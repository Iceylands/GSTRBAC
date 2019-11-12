/*
1- capitalized the name of the class roleHierarchy (Mustafa 2-5-19)
2- Fixed the inheritance here. The RoleHierarchy class is the
base class for the both A_Hierarchy and I_Hierarchy (Mustafa 2-5-19)
3- Commented the two include directives since they are not needed
anymore after fixing the structure of the hierarchy (Mustafa 2-5-19)

*/
//takes seniorRole, juniorRole from role class, takes zone from STZone
#include "A_Hierarchy.h"
#include "I_Hierarchy.h"
#include "STZone.h" 
//class RoleHierarchy: public A_Hierarchy, public I_Hierarchy {
#ifndef ROLEHIERARCHY_H
#define ROLEHIERARCHY_H
class Role;
class STZone;
class RoleHierarchy {

public:
	RoleHierarchy(STZone&, Role&, Role*);
	//RoleHierarchy(STZone& z, Role& junior, Role* link) :zone(z), juniorRole(junior), us(link) {
	//currently trying to generate an overloaded function to place links
	//}
	STZone& getZone();

	Role& getJRole();

	Role* getSRole();

private:
	STZone& zone;//RHZone association
	Role& juniorRole;//RH1Role association
	Role* seniorRole;//RH2Role association
	//Role* us;
};

#endif

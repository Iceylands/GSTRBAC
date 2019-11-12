/* Update notes:
1- Capitalized the name of the class, it was a_Hierarchy (Mustafa 2-5-19)
2- Fixed the RoleHierarchy inheritance. A_Hierarchy should inherit from 
RoleHierarchy not the opposite ( Mustafa 2-5-19) 
3- Included the header of the RoleHierarchy class to allow inheritanc (Mustafa 2-5-19) 
*/


#ifndef A_HIERARCHY_H
#define A_HIERARCHY_H
#include "RoleHierarchy.h"
class A_Hierarchy: public RoleHierarchy {
public:
	A_Hierarchy(STZone& z, Role& junior, Role* senior);
private:

};

#endif
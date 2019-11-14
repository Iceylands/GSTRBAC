#ifndef SOD_H
#define SOD_H
#include "Role.h"
#include <vector>
#include <array>
class STZone;
class SOD  {
public:
	SOD(STZone& z, Role& first, Role* second);
	const std::array<Role*, 2> & getInvolvedRoles();
	STZone& getZone();
	Role& getFirstRole();
	Role* getSecondRole();
private:
	STZone& zone;
	Role& firstRole;//SOD1Role association
	Role* secondRole;//SOD2Role association
};
#endif //SOD_H

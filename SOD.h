#ifndef SOD_H
#define SOD_H
#include "Role.h"
#include <vector>
#include <array>
class STZone;
class SOD  {
public:
	SOD(STZone& z, Role& first, Role* second) :zone(z), firstRole(first), secondRole(second) {

	}
	const std::array<Role*, 2> & getInvolvedRoles() {
		std::array<Role*, 2> irArray{ &firstRole , secondRole };
		return irArray;
	}
	STZone& getZone() {
		return zone;
	}
	Role& getFirstRole() {
		return firstRole;
	}
	Role* getSecondRole() {
		return secondRole;
	}
private:
	STZone& zone;
	Role& firstRole;//SOD1Role association
	Role* secondRole;//SOD2Role association
};
#endif //SOD_H

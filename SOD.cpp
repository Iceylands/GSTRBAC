
#include "SOD.h"

SOD::SOD(STZone& z, Role& first, Role* second) :zone(z), firstRole(first), secondRole(second) {

}
const std::array<Role*, 2>& SOD::getInvolvedRoles() {
	std::array<Role*, 2> irArray{ &firstRole , secondRole };
	return irArray;
}
STZone& SOD::getZone() {
	return zone;
}
Role& SOD::getFirstRole() {
	return firstRole;
}
Role* SOD::getSecondRole() {
	return secondRole;
}
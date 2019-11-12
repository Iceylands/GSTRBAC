#include "Role.h"
#include "SOD.h"
#include <array>
class STZone;

using namespace std;

SOD::SOD(STZone& z, Role& first, Role* second) :zone(z), firstRole(first), secondRole(second) {

}
const vector<Role&>& SOD::getInvolvedRoles() {
	vector<Role&> involvedRoles;
	involvedRoles.push_back(firstRole);
	involvedRoles.push_back(*secondRole);
	return involvedRoles;
};
STZone& SOD::getZone() {
	return zone;
}
Role& SOD::getFirstRole() {
	return firstRole;
}
Role* SOD::getSecondRole() {
	return secondRole;
}
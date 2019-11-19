#include <vector>
#include "Permission.h"
#include "STZone.h"
#include "PSSOD.h"

PSSOD::PSSOD(STZone& z, Permission* first, Permission& second) :zone(z), firstPermission(first), secondPermission(second) {

}
const std::vector<Permission>& PSSOD::getInvolvedPermissions() { //2/18/2019 These three are not working
	std::vector<Permission> involvedPermissions;
	return involvedPermissions;
}
STZone& PSSOD::getZone() {
	return zone;
}
Permission* PSSOD::getFirstPermission() {
	return firstPermission;
}
Permission& PSSOD::getSecondPermission() {
	return secondPermission;
}
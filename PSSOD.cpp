#include <vector>
#include <array>
#include "Permission.h"
#include "STZone.h"
#include "PSSOD.h"

PSSOD::PSSOD(STZone& z, Permission* first, Permission& second) :zone(z), firstPermission(first), secondPermission(second) {

}
const std::array<Permission*, 2>& PSSOD::getInvolvedPermissions() { //2/18/2019 These three are not working
	std::array<Permission*, 2> ipArray{ firstPermission, &secondPermission };
	return ipArray;
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
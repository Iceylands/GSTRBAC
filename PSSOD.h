//takes firstPermission, secondPermission from Permission class
//takes zone from stzone
//creates pssod
#ifndef PSSOD_H
#define PSSOD_H
#include "Permission.h" // Included Permission -Rey 9-17-19
#include <vector>
#include <array>
class Permission;
class STZone;
class PSSOD {
public:
	PSSOD(STZone&, Permission*, Permission&);

	const std::array<Permission*, 2>& getInvolvedPermissions();

	 STZone& getZone();

	 Permission* getFirstPermission();

	 Permission& getSecondPermission();

private:
	STZone& zone;//PSSODZone association
	Permission* firstPermission;//PSSOD1Permission association
	Permission& secondPermission;//PSSOD2Permission association
};
#endif

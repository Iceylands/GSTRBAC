//takes values from stzone, object, and activity
//creates permission, secondPermission, firstPermission

class STZone;
class Object;
class Activity;
class PSSOD;

//#include "STZone.h"
#include <vector>
#ifndef PERMISSION_H
#define PERMISSION_H
#include "PSSOD.h"
#include <string>
class Permission {
public:
	Permission(std::vector<STZone>&, Object&, Activity&, std::vector<PSSOD>&, std::vector<PSSOD>&);
	const PSSOD& addSoDPermission(Permission&, STZone&);
	void deleteSoDPermission(Permission&, STZone&);
	const std::vector<Permission>& getSoDPermission(STZone&);
	const std::vector<Permission>& getPrerequisitePermissions();
	std::vector<STZone>& getPermissionZones();
	Object& getPermissionObject();
	Activity& getActivity();
	std::vector<PSSOD>& getPermission1();
	std::vector<PSSOD>& getPermission2();
	void enableZone(STZone&);

private:
	std::vector<STZone>& zones;//PermissionZone association
	Object& object;//PermissionObject aggregation
	Activity& activity;//PermissionActivity aggregation
	std::vector<PSSOD>& pssod;//PSSOD1Permission association
	std::vector<PSSOD>& Pssod;//PSSOD2Permission association
};
#endif

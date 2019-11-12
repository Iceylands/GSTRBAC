// inherits ozones from stzones
// creates object
#ifndef OBJECT_H
#define OBJECT_H
class STZone;
class Permission;
#include <vector>
class Object {
public:
	Object(std::string, std::vector<STZone>&, std::vector<Permission>&);

	void enableZone(STZone&);

	std::vector<STZone>& getObjZones();

	std::vector<Permission>& getObjPermissions();

private:
	std::vector<STZone>& zones;//ObjectZone association
	std::vector<Permission>& permissions;//PermissionObject aggregation
	std::string& name;
};
#endif

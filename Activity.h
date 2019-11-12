#pragma once
//no heirarchy inheritance
//is used to create permission class
#ifndef ACTIVITY_H 
#define ACTIVITY_H
#include <vector>
class Permission;
class Activity {
public:
	Activity(std::vector<Permission>& perm);
	std::vector<Permission>& getPermissions();
private:
	std::vector<Permission>& permission;//PermissionActivity aggregation
};
#endif // !
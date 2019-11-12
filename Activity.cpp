#include "Activity.h"
//test comment 231
Activity::Activity(std::vector<Permission>& perm) :permission(perm) {};

std::vector<Permission>& Activity::getPermissions() {
	return permission;
}
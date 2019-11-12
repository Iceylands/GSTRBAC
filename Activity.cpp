#include "Activity.h"

Activity::Activity(std::vector<Permission>& perm) :permission(perm) {};

std::vector<Permission>& Activity::getPermissions() {
	return permission;
}
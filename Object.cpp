#include <vector>
#include "Object.h"
#include "STZone.h"
#include "Permission.h"

Object::Object(std::string n, std::vector<STZone>& obZones, std::vector<Permission>& objPerms) : name{ n }, zones{ obZones }, permissions{ objPerms } {

}
void Object::enableZone(STZone& z) {
	zones.push_back(z);
	}
std::vector<STZone>& Object::getObjZones() {
	return zones;
}
std::vector<Permission>& Object::getObjPermissions() {
	return permissions;
}
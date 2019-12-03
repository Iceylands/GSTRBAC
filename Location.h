//this class is part of the STZone
// carries over location value
#ifndef LOCATION_H
#define LOCATION_H
class STZone;
#include <vector>
#include <string>
class Location {
public:
	Location(const std::vector<STZone>& locZones) : includes(locZones) {
		
	}

	Location(std::string n) : name{ n } {

	}

	std::vector<STZone>& getLZones() {
		return includes;
	}
private:
	std::vector<STZone> includes;//works
	std::string name;
};
#endif

//this class is part of the STZone
// carries over location value
#ifndef LOCATION_H
#define LOCATION_H
class STZone;
#include <vector>
class Location {
public:
	Location(std::vector<STZone>& locZones) : includes(locZones) {
		
	}
	std::vector<STZone>& getLZones() {
		return includes;
	}
private:
	std::vector<STZone>& includes;//works

};
#endif

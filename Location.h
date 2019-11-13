//this class is part of the STZone
// carries over location value
#ifndef LOCATION_H
#define LOCATION_H
class STZone;
#include <vector>
class Location {
public:
	Location(std::vector<STZone>&);

	std::vector<STZone>& getLZones();

private:
	std::vector<STZone>& includes;//works

};
#endif

#include "TimeInterval.h"
#include <vector>
#include <string>

TimeInterval::TimeInterval(/*std::string intervalName,*/std::vector<STZone>& z) :/*name(intervalName),*/include(z) {
}
std::vector<STZone>& TimeInterval::getTimeZones() {
	return include;
}
std::string& TimeInterval::getName() {
	return name;
}
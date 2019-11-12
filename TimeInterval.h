//1- Seperated code into two files (Miguelangel 9-17-19)
//This class is a component of the STZone class
//carries over interval 
#ifndef TIMEINTERVAL_H
#define TIMEINTERVAL_H
#include <vector>
#include <string>
#include "STZone.h" // added this STZone -Rey 9-17-19
class STZone;
class TimeInterval {
public:
	TimeInterval(/*std::string intervalName,*/std::vector<STZone>& z);

	std::vector<STZone>& getTimeZones();

	std::string& getName();

private:
	std::vector<STZone>& include;//ZoneTimeInterval aggregation 
	std::string name;


};
#endif
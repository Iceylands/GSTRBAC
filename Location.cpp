


#include "Location.h"
#include "STZone.h"

using namespace std;


Location::Location(vector<STZone>& locZones) : includes(locZones)
{

}

vector<STZone>& Location::getLZones()
{
	return includes;
}
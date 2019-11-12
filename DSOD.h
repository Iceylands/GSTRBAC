//base class of SOD
#ifndef DSOD_H
#define DSOD_H
#include "SOD.h"

class DSOD: public SOD {
public:
	DSOD(STZone& z, Role& first, Role* second) :SOD::SOD(z, first, second) {

	}
private:

};
#endif

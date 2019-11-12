//base class for SOD
#ifndef SSOD_H
#define SSOD_H
#include "SOD.h"
class SSOD: public SOD {
public:
	SSOD(STZone& z, Role& first, Role* second) :SOD::SOD(z, first, second) {
	}


private:

};
#endif

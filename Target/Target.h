/*
 * Target.h
 *
 * Created on : 20-01-2020 09:00
 *	   Author : eren.dere
 */

#ifndef TARGET_H_
#define TARGET_H_

#include <Vehicle.h>

#include "VehicleMechanics.h"

class Target: public Vehicle {
private:
	Module *posInfo;

public:
	Target();

	virtual ~Target();

	void createModules();

	Module *getPOSINFO() {
			return posInfo;
	}
};

#endif /* TARGET_H_ */

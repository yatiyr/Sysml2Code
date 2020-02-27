/*
 * Object.h
 *
 * Created on : 20-01-2020 09:00
 *	   Author : eren.dere
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include <Vehicle.h>

#include "Propulsion.h"
#include "Aerodynamics.h"
#include "MassInertia.h"
#include "Gravity.h"
#include "FlightMechanics.h"

class Object: public Vehicle {
private:
	Module *massInertia;
	Module *aerodynamics;
	Module *gravity;
	Module *propulsion;
	Module *flightMechanics;

public:
	Object();

	virtual ~Object();

	void createModules();

	Module *getMASSINERTIA() {
			return massInertia;
	}
	Module *getAERODYNAMICS() {
			return aerodynamics;
	}
	Module *getGRAVITY() {
			return gravity;
	}
	Module *getPROPULSION() {
			return propulsion;
	}
	Module *getFLIGHTMECHANICS() {
			return flightMechanics;
	}
};

#endif /* OBJECT_H_ */

/*
 * AirVehicle.h
 *
 * Created on : 02-03-2020 04:01
 *	   Author : eren.dere
 */

#ifndef AIRVEHICLE_H_
#define AIRVEHICLE_H_

#include <Control_.h>
#include <FlightMechanics_.h>
#include <Vehicle.h>

#include "Propulsion.h"
#include "Aerodynamics.h"
#include "MassInertia.h"
#include "Gravity.h"
#include "Sensor.h"

class AirVehicle: public Vehicle {
private:
	Module *massInertia;
	Module *aerodynamics;
	Module *gravity;
	Module *propulsion;
	Module *flightMechanics;
	Module *sensor;
	Module *control;

public:
	AirVehicle();

	virtual ~AirVehicle();

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
	Module *getSENSOR() {
			return sensor;
	}
	Module *getCONTROL() {
			return control;
	}
};

#endif /* AIRVEHICLE_H_ */

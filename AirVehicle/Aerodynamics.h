
/*
 * Aerodynamics.h
 * Created on : 02-03-2020 04:01
 *	   Author : eren.dere
 */

#ifndef AERODYNAMICS_H_
#define AERODYNAMICS_H_

#include "Module.h"

class Aerodynamics: public Module {
protected:
	Matrix aero_force;
	Matrix aero_moment;

public:
	Aerodynamics();
	virtual ~Aerodynamics();

	void initialize();
	void act();
	void sendEngagementData();

	Matrix get_aero_force() const {
		return aero_force;
	}
	Matrix get_aero_moment() const {
		return aero_moment;
	}

};

#endif /* AERODYNAMICS_H_ */

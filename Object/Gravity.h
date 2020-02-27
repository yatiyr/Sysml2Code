/*
 * Gravity.h
 * Created on : 20-01-2020 09:00
 *	   Author : eren.dere
 */

#ifndef GRAVITY_H_
#define GRAVITY_H_

#include "Module.h"

class Gravity: public Module {
protected:
	Matrix gravitational_force;

public:
	Gravity();
	virtual ~Gravity();

	void initialize();
	void act();
	void sendEngagementData();

	Matrix get_gravitational_force() const {
		return gravitational_force;
	}

};

#endif /* GRAVITY_H_ */

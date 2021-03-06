
/*
 * Propulsion.h
 * Created on : 02-03-2020 04:01
 *	   Author : eren.dere
 */

#ifndef PROPULSION_H_
#define PROPULSION_H_

#include "Module.h"

class Propulsion: public Module {
protected:
	Matrix prop_force;
	Matrix prop_moment;

public:
	Propulsion();
	virtual ~Propulsion();

	void initialize();
	void act();
	void sendEngagementData();

	Matrix get_prop_force() const {
		return prop_force;
	}
	Matrix get_prop_moment() const {
		return prop_moment;
	}

};

#endif /* PROPULSION_H_ */

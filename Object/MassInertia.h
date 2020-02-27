/*
 * MassInertia.h
 * Created on : 20-01-2020 09:00
 *	   Author : eren.dere
 */

#ifndef MASSINERTIA_H_
#define MASSINERTIA_H_

#include "Module.h"

class MassInertia: public Module {
protected:
	Matrix inertia;
	Matrix inertia_dot;
	double mass;
	Matrix xcg;

public:
	MassInertia();
	virtual ~MassInertia();

	void initialize();
	void act();
	void sendEngagementData();

	Matrix get_inertia() const {
		return inertia;
	}
	Matrix get_inertia_dot() const {
		return inertia_dot;
	}
	double get_mass() const {
		return mass;
	}
	Matrix get_xcg() const {
		return xcg;
	}

};

#endif /* MASSINERTIA_H_ */

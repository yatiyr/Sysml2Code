/*
 * VehicleMechanics.h
 * Created on : 20-01-2020 09:00
 *	   Author : eren.dere
 */

#ifndef VEHICLEMECHANICS_H_
#define VEHICLEMECHANICS_H_

#include "Module.h"

class VehicleMechanics: public Module {
protected:
	Matrix xyz;

public:
	VehicleMechanics();
	virtual ~VehicleMechanics();

	void initialize();
	void act();
	void sendEngagementData();

	Matrix get_xyz() const {
		return xyz;
	}

};

#endif /* VEHICLEMECHANICS_H_ */

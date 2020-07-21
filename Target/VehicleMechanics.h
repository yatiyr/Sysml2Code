
/*
 * VehicleMechanics.h
 * Created on : 02-03-2020 04:01
 *	   Author : eren.dere
 */

#ifndef VEHICLEMECHANICS_H_
#define VEHICLEMECHANICS_H_

#include "Module.h"
#include <fstream>

class VehicleMechanics: public Module {
protected:
	Matrix position;
	std::ofstream xPos;
	std::ofstream yPos;

public:
	VehicleMechanics();
	virtual ~VehicleMechanics();

	void initialize();
	void act();
	void sendEngagementData();

	Matrix get_position() const {
		return position;
	}


};

#endif /* VEHICLEMECHANICS_H_ */

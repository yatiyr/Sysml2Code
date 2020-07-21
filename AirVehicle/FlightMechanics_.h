
/*
 * FlightMechanics.h
 * Created on : 02-03-2020 04:01
 *	   Author : eren.dere
 */

#ifndef FLIGHTMECHANICS__H_
#define FLIGHTMECHANICS__H_

#include "Module.h"
#include <fstream>

class FlightMechanics_: public Module {
protected:
	double alpha;
	double beta;
	Matrix velocity;
	Matrix angularVelocity;
	Matrix position;
	Matrix orientation;
	Matrix acceleration;
	Matrix DCM;
	double speed;
	std::ofstream outDataX;
	std::ofstream outDataY;

	std::ofstream velX;
	std::ofstream velY;

public:
	FlightMechanics_();
	virtual ~FlightMechanics_();

	void initialize();
	void act();
	void sendEngagementData();

	double get_alpha() const {
		return alpha;
	}
	double get_beta() const {
		return beta;
	}
	Matrix get_velocity() const {
		return velocity;
	}
	Matrix get_angularVelocity() const {
		return angularVelocity;
	}
	Matrix get_position() const {
		return position;
	}
	Matrix get_orientation() const {
		return orientation;
	}
	Matrix get_acceleration() const {
		return acceleration;
	}
	Matrix get_DCM() const {
		return DCM;
	}
	double get_speed() const {
		return speed;
	}

};

#endif /* FLIGHTMECHANICS__H_ */

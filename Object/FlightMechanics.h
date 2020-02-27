/*
 * FlightMechanics.h
 * Created on : 20-01-2020 09:00
 *	   Author : eren.dere
 */

#ifndef FLIGHTMECHANICS_H_
#define FLIGHTMECHANICS_H_

#include "Module.h"

class FlightMechanics: public Module {
protected:
	double alpha;
	double beta;
	Matrix vel_BE_B;
	Matrix om_BI_B;
	bool boost_coast;
	Matrix DCM_be;
	Matrix pos_BE_B;
	Matrix euler_angles;
	Matrix a_BE_B;
	Matrix DCM_bf;
	Matrix DCM_bi;
	Matrix DCM_if;
	Matrix DCM_ef;
	Matrix DCM;
	Matrix LLA;
	Matrix pos_BI_B;
	Matrix om_BI_B_dot;
	Matrix quat_BE;
	Matrix quat_BE_dot;
	double speed;
	Matrix force_B;
	Matrix moment_B;

public:
	FlightMechanics();
	virtual ~FlightMechanics();

	void initialize();
	void act();
	void sendEngagementData();

	double get_alpha() const {
		return alpha;
	}
	double get_beta() const {
		return beta;
	}
	Matrix get_vel_BE_B() const {
		return vel_BE_B;
	}
	Matrix get_om_BI_B() const {
		return om_BI_B;
	}
	bool get_boost_coast() const {
		return boost_coast;
	}
	Matrix get_DCM_be() const {
		return DCM_be;
	}
	Matrix get_pos_BE_B() const {
		return pos_BE_B;
	}
	Matrix get_euler_angles() const {
		return euler_angles;
	}
	Matrix get_a_BE_B() const {
		return a_BE_B;
	}
	Matrix get_DCM_bf() const {
		return DCM_bf;
	}
	Matrix get_DCM_bi() const {
		return DCM_bi;
	}
	Matrix get_DCM_if() const {
		return DCM_if;
	}
	Matrix get_DCM_ef() const {
		return DCM_ef;
	}
	Matrix get_DCM() const {
		return DCM;
	}
	Matrix get_LLA() const {
		return LLA;
	}
	Matrix get_pos_BI_B() const {
		return pos_BI_B;
	}
	Matrix get_om_BI_B_dot() const {
		return om_BI_B_dot;
	}
	Matrix get_quat_BE() const {
		return quat_BE;
	}
	Matrix get_quat_BE_dot() const {
		return quat_BE_dot;
	}
	double get_speed() const {
		return speed;
	}
	Matrix get_force_B() const {
		return force_B;
	}
	Matrix get_moment_B() const {
		return moment_B;
	}

};

#endif /* FLIGHTMECHANICS_H_ */

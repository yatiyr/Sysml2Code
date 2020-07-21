
/*
 * Control.h
 * Created on : 02-03-2020 04:01
 *	   Author : eren.dere
 */

#ifndef CONTROL__H_
#define CONTROL__H_

#include "Module.h"

class Control_: public Module {
protected:
	Matrix externalForce;

public:
	Control_();
	virtual ~Control_();

	void initialize();
	void act();
	void sendEngagementData();

	Matrix get_externalForce() const {
		return externalForce;
	}

};

#endif /* CONTROL_H_ */

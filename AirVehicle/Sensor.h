
/*
 * Sensor.h
 * Created on : 02-03-2020 04:01
 *	   Author : eren.dere
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include "Module.h"

class Sensor: public Module {
protected:
	Matrix sensorData;
	Matrix FOV;

public:
	Sensor();
	virtual ~Sensor();

	void initialize();
	void act();
	void sendEngagementData();

	Matrix get_sensorData() const {
		return sensorData;
	}
	Matrix get_FOV() const {
		return FOV;
	}

};

#endif /* SENSOR_H_ */

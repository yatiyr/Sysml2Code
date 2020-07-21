/*
 * Sensor.cpp
 * Created on : 02-03-2020 04:01
 *	   Author : eren.dere
 */

#include "Sensor.h"

#include <Simulator.h>
#include <EngagementData.h>

extern Simulator *simulator;

Sensor::Sensor() {


}

Sensor::~Sensor() {

}

void Sensor::initialize(){
	// TODO : user must write initial values 
	// additional variables can be introduced

	this->sensorData = Matrix(3,1);  // TODO: Give value;
	this->FOV = Matrix(3,1); // TODO: Give value;
}

void Sensor::sendEngagementData() {


}

void Sensor::act() {

	// local variables coming from the connections
	Matrix position;
	Matrix orientation;
	
	


	try {
		Connection *connection_flightMechanics_sensor = connectionMap.at("position");
		ServiceFunction *handler_flightMechanics_sensor = new ServiceFunction();
		handler_flightMechanics_sensor->Matrix_function = connection_flightMechanics_sensor->getHandler().Matrix_function;
		position = handler_flightMechanics_sensor->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_flightMechanics_sensor = connectionMap.at("orientation");
		ServiceFunction *handler_flightMechanics_sensor = new ServiceFunction();
		handler_flightMechanics_sensor->Matrix_function = connection_flightMechanics_sensor->getHandler().Matrix_function;
		orientation = handler_flightMechanics_sensor->Matrix_function();
	} catch(std::exception &e) {}



	/**
	 * TODO User should specify the behaviour of the module by 
	 * writing code to this part.
     */
}


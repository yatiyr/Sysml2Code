/*
 * Control.cpp
 * Created on : 02-03-2020 04:01
 *	   Author : eren.dere
 */

#include <Control_.h>
#include <Simulator.h>
#include <EngagementData.h>

extern Simulator *simulator;

Control_::Control_() {


}

Control_::~Control_() {

}

void Control_::initialize(){
	// TODO : user must write initial values 
	// additional variables can be introduced

	this->externalForce = Matrix(3,1);  // TODO: Give value;
}

void Control_::sendEngagementData() {


}

void Control_::act() {

	// local variables coming from the connections
	Matrix sensorData;
	
	


	try {
		Connection *connection_sensor_control = connectionMap.at("sensorData");
		ServiceFunction *handler_sensor_control = new ServiceFunction();
		handler_sensor_control->Matrix_function = connection_sensor_control->getHandler().Matrix_function;
		sensorData = handler_sensor_control->Matrix_function();
	} catch(std::exception &e) {}



	/**
	 * TODO User should specify the behaviour of the module by 
	 * writing code to this part.
     */
}


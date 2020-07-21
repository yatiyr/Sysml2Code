/*
 * Gravity.cpp
 * Created on : 02-03-2020 04:01
 *	   Author : eren.dere
 */

#include "Gravity.h"

#include <Simulator.h>
#include <EngagementData.h>

extern Simulator *simulator;

Gravity::Gravity() {


}

Gravity::~Gravity() {

}

void Gravity::initialize(){
	// TODO : user must write initial values 
	// additional variables can be introduced

	this->gravitational_force = Matrix(3,1);
	this->gravitational_force(1,0) = 9.8;// TODO: Give value;
}

void Gravity::sendEngagementData() {


}

void Gravity::act() {

	// local variables coming from the connections
	Matrix DCM;
	double mass = 0;
	
	


	try {
		Connection *connection_flightMechanics_gravity = connectionMap.at("DCM");
		ServiceFunction *handler_flightMechanics_gravity = new ServiceFunction();
		handler_flightMechanics_gravity->Matrix_function = connection_flightMechanics_gravity->getHandler().Matrix_function;
		DCM = handler_flightMechanics_gravity->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_massInertia_gravity = connectionMap.at("mass");
		ServiceFunction *handler_massInertia_gravity = new ServiceFunction();
		handler_massInertia_gravity->double_function = connection_massInertia_gravity->getHandler().double_function;
		mass = handler_massInertia_gravity->double_function();
	} catch(std::exception &e) {}



	/**
	 * TODO User should specify the behaviour of the module by 
	 * writing code to this part.
     */
}


/*
 * Aerodynamics.cpp
 * Created on : 02-03-2020 04:01
 *	   Author : eren.dere
 */

#include "Aerodynamics.h"

#include <Simulator.h>
#include <EngagementData.h>

extern Simulator *simulator;

Aerodynamics::Aerodynamics() {


}

Aerodynamics::~Aerodynamics() {

}

void Aerodynamics::initialize(){
	// TODO : user must write initial values
	// additional variables can be introduced

	this->aero_force = Matrix(3,1); // TODO: Give value;
	this->aero_moment = Matrix(3,1); // TODO: Give value;
}

void Aerodynamics::sendEngagementData() {


}

void Aerodynamics::act() {

	// local variables coming from the connections
	double beta = 0;
	Matrix xcg;
	Matrix velocity;
	Matrix angularVelocity;
	double alpha = 0;
	
	


	try {
		Connection *connection_flightMechanics_aerodynamics = connectionMap.at("beta");
		ServiceFunction *handler_flightMechanics_aerodynamics = new ServiceFunction();
		handler_flightMechanics_aerodynamics->double_function = connection_flightMechanics_aerodynamics->getHandler().double_function;
		beta = handler_flightMechanics_aerodynamics->double_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_massInertia_aerodynamics = connectionMap.at("xcg");
		ServiceFunction *handler_massInertia_aerodynamics = new ServiceFunction();
		handler_massInertia_aerodynamics->Matrix_function = connection_massInertia_aerodynamics->getHandler().Matrix_function;
		xcg = handler_massInertia_aerodynamics->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_flightMechanics_aerodynamics = connectionMap.at("velocity");
		ServiceFunction *handler_flightMechanics_aerodynamics = new ServiceFunction();
		handler_flightMechanics_aerodynamics->Matrix_function = connection_flightMechanics_aerodynamics->getHandler().Matrix_function;
		velocity = handler_flightMechanics_aerodynamics->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_flightMechanics_aerodynamics = connectionMap.at("angularVelocity");
		ServiceFunction *handler_flightMechanics_aerodynamics = new ServiceFunction();
		handler_flightMechanics_aerodynamics->Matrix_function = connection_flightMechanics_aerodynamics->getHandler().Matrix_function;
		angularVelocity = handler_flightMechanics_aerodynamics->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_flightMechanics_aerodynamics = connectionMap.at("alpha");
		ServiceFunction *handler_flightMechanics_aerodynamics = new ServiceFunction();
		handler_flightMechanics_aerodynamics->double_function = connection_flightMechanics_aerodynamics->getHandler().double_function;
		alpha = handler_flightMechanics_aerodynamics->double_function();
	} catch(std::exception &e) {}



	/**
	 * TODO User should specify the behaviour of the module by 
	 * writing code to this part.
     */
}


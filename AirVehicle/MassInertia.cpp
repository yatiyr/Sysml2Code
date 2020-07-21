/*
 * MassInertia.cpp
 * Created on : 02-03-2020 04:01
 *	   Author : eren.dere
 */

#include "MassInertia.h"

#include <Simulator.h>
#include <EngagementData.h>

extern Simulator *simulator;

MassInertia::MassInertia() {


}

MassInertia::~MassInertia() {

}

void MassInertia::initialize(){
	// TODO : user must write initial values 
	// additional variables can be introduced

	this->inertia = Matrix(3,1); // TODO: Give value;
	this->inertia_dot = Matrix(3,1);  // TODO: Give value;
	this->mass = 0; // TODO: Give value;
	this->xcg = Matrix(3,1);  // TODO: Give value;
}

void MassInertia::sendEngagementData() {


}

void MassInertia::act() {

	// local variables coming from the connections
	Matrix pos_BE_B;
	
	


	try {
		Connection *connection_flightMechanics_massInertia = connectionMap.at("pos_BE_B");
		ServiceFunction *handler_flightMechanics_massInertia = new ServiceFunction();
		handler_flightMechanics_massInertia->Matrix_function = connection_flightMechanics_massInertia->getHandler().Matrix_function;
		pos_BE_B = handler_flightMechanics_massInertia->Matrix_function();
	} catch(std::exception &e) {}



	/**
	 * TODO User should specify the behaviour of the module by 
	 * writing code to this part.
     */
}


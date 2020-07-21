/*
 * Propulsion.cpp
 * Created on : 02-03-2020 04:01
 *	   Author : eren.dere
 */

#include "Propulsion.h"

#include <Simulator.h>
#include <EngagementData.h>

extern Simulator *simulator;

Propulsion::Propulsion() {


}

Propulsion::~Propulsion() {

}

void Propulsion::initialize(){
	// TODO : user must write initial values 
	// additional variables can be introduced

	this->prop_force = Matrix(3,1); // TODO: Give value;
	this->prop_moment = Matrix(3,1); // TODO: Give value;
}

void Propulsion::sendEngagementData() {


}

void Propulsion::act() {

	// local variables coming from the connections
	Matrix xcg;
	
	


	try {
		Connection *connection_massInertia_propulsion = connectionMap.at("xcg");
		ServiceFunction *handler_massInertia_propulsion = new ServiceFunction();
		handler_massInertia_propulsion->Matrix_function = connection_massInertia_propulsion->getHandler().Matrix_function;
		xcg = handler_massInertia_propulsion->Matrix_function();
	} catch(std::exception &e) {}



	/**
	 * TODO User should specify the behaviour of the module by 
	 * writing code to this part.
     */
}


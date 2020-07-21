/*
 * FlightMechanics.cpp
 * Created on : 02-03-2020 04:01
 *	   Author : eren.dere
 */

#include <Simulator.h>
#include <EngagementData.h>
#include <FlightMechanics_.h>
#include <Module.h>

extern Simulator *simulator;

FlightMechanics_::FlightMechanics_() {


}

FlightMechanics_::~FlightMechanics_() {

}

void FlightMechanics_::initialize(){
	// TODO : user must write initial values 
	// additional variables can be introduced

	this->alpha = 0; // TODO: Give value;
	this->beta =  0; // TODO: Give value;
	this->velocity = Matrix(3,1);
	this->velocity(0,0) = 30;
	this->velocity(1,0) = 100;
	this->velocity(2,0) = 0;// TODO: Give value;
	this->angularVelocity = Matrix(3,1); // TODO: Give value;
	this->position = Matrix(3,1); // TODO: Give value;
	this->orientation = Matrix(3,1); // TODO: Give value;
	this->acceleration =  Matrix(3,1);// TODO: Give value;
	this->DCM = Matrix(3,1); // TODO: Give value;
	this->speed = 0; // TODO: Give value;
	this->outDataX.open("xPos.txt");
	this->outDataY.open("yPos.txt");
	this->velX.open("xVel.txt");
	this->velY.open("yVel.txt");
}

void FlightMechanics_::sendEngagementData() {


}

void FlightMechanics_::act() {

	// local variables coming from the connections
	Matrix externalForces;
	Matrix aero_moment;
	Matrix inertia_dot;
	Matrix aero_force;
	Matrix prop_moment;
	Matrix prop_force;
	Matrix inertia;
	double mass = 0;
	Matrix gravitational_force;
	
	


	try {
		Connection *connection_control_flightMechanics = connectionMap.at("externalForces");
		ServiceFunction *handler_control_flightMechanics = new ServiceFunction();
		handler_control_flightMechanics->Matrix_function = connection_control_flightMechanics->getHandler().Matrix_function;
		externalForces = handler_control_flightMechanics->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_aerodynamics_flightMechanics = connectionMap.at("aero_moment");
		ServiceFunction *handler_aerodynamics_flightMechanics = new ServiceFunction();
		handler_aerodynamics_flightMechanics->Matrix_function = connection_aerodynamics_flightMechanics->getHandler().Matrix_function;
		aero_moment = handler_aerodynamics_flightMechanics->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_massInertia_flightMechanics = connectionMap.at("inertia_dot");
		ServiceFunction *handler_massInertia_flightMechanics = new ServiceFunction();
		handler_massInertia_flightMechanics->Matrix_function = connection_massInertia_flightMechanics->getHandler().Matrix_function;
		inertia_dot = handler_massInertia_flightMechanics->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_aerodynamics_flightMechanics = connectionMap.at("aero_force");
		ServiceFunction *handler_aerodynamics_flightMechanics = new ServiceFunction();
		handler_aerodynamics_flightMechanics->Matrix_function = connection_aerodynamics_flightMechanics->getHandler().Matrix_function;
		aero_force = handler_aerodynamics_flightMechanics->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_propulsion_flightMechanics = connectionMap.at("prop_moment");
		ServiceFunction *handler_propulsion_flightMechanics = new ServiceFunction();
		handler_propulsion_flightMechanics->Matrix_function = connection_propulsion_flightMechanics->getHandler().Matrix_function;
		prop_moment = handler_propulsion_flightMechanics->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_propulsion_flightMechanics = connectionMap.at("prop_force");
		ServiceFunction *handler_propulsion_flightMechanics = new ServiceFunction();
		handler_propulsion_flightMechanics->Matrix_function = connection_propulsion_flightMechanics->getHandler().Matrix_function;
		prop_force = handler_propulsion_flightMechanics->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_massInertia_flightMechanics = connectionMap.at("inertia");
		ServiceFunction *handler_massInertia_flightMechanics = new ServiceFunction();
		handler_massInertia_flightMechanics->Matrix_function = connection_massInertia_flightMechanics->getHandler().Matrix_function;
		inertia = handler_massInertia_flightMechanics->Matrix_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_massInertia_flightMechanics = connectionMap.at("mass");
		ServiceFunction *handler_massInertia_flightMechanics = new ServiceFunction();
		handler_massInertia_flightMechanics->double_function = connection_massInertia_flightMechanics->getHandler().double_function;
		mass = handler_massInertia_flightMechanics->double_function();
	} catch(std::exception &e) {}

	try {
		Connection *connection_gravity_flightMechanics = connectionMap.at("gravitational_force");
		ServiceFunction *handler_gravity_flightMechanics = new ServiceFunction();
		handler_gravity_flightMechanics->Matrix_function = connection_gravity_flightMechanics->getHandler().Matrix_function;
		gravitational_force = handler_gravity_flightMechanics->Matrix_function();
	} catch(std::exception &e) {}


	/**
	 * TODO User should specify the behaviour of the module by 
	 * writing code to this part.
     */

	//std::cout << gravitational_force(1,0) << std::endl;

	this->velocity(1,0) -= gravitational_force(1,0)*simulator->getTimeStep();

	//std::cout << this->velocity(1,0) << std::endl;

	this->position += this->velocity*simulator->getTimeStep();

	outDataX << this->position(0,0) << std::endl;
	outDataY << this->position(1,0) << std::endl;

	velX << this->velocity(0,0) << std::endl;
	velY << this->velocity(1,0) << std::endl;

}


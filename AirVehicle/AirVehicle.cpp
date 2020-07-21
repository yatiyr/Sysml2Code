/*
 * AirVehicle.cpp
 *
 * Created on : 02-03-2020 04:01
 *	   Author : eren.dere
 */

#include "AirVehicle.h"
#include <Utils.h>
#include <Simulator.h>

extern Simulator *simulator;


AirVehicle::AirVehicle() {

}

AirVehicle::~AirVehicle() {

}



void AirVehicle::createModules() {


	massInertia = new MassInertia();
	massInertia->setName("massInertia");
	massInertia->setLaunchTime(this->getLaunchTime());
	massInertia->setExitSimulationTime(this->getExitSimulationTime());
	simulator->getEngagement()->registerModule(massInertia);


	aerodynamics = new Aerodynamics();
	aerodynamics->setName("aerodynamics");
	aerodynamics->setLaunchTime(this->getLaunchTime());
	aerodynamics->setExitSimulationTime(this->getExitSimulationTime());
	simulator->getEngagement()->registerModule(aerodynamics);


	gravity = new Gravity();
	gravity->setName("gravity");
	gravity->setLaunchTime(this->getLaunchTime());
	gravity->setExitSimulationTime(this->getExitSimulationTime());
	simulator->getEngagement()->registerModule(gravity);


	propulsion = new Propulsion();
	propulsion->setName("propulsion");
	propulsion->setLaunchTime(this->getLaunchTime());
	propulsion->setExitSimulationTime(this->getExitSimulationTime());
	simulator->getEngagement()->registerModule(propulsion);


	flightMechanics = new FlightMechanics_();
	flightMechanics->setName("flightMechanics");
	flightMechanics->setLaunchTime(this->getLaunchTime());
	flightMechanics->setExitSimulationTime(this->getExitSimulationTime());
	simulator->getEngagement()->registerModule(flightMechanics);


	sensor = new Sensor();
	sensor->setName("sensor");
	sensor->setLaunchTime(this->getLaunchTime());
	sensor->setExitSimulationTime(this->getExitSimulationTime());
	simulator->getEngagement()->registerModule(sensor);
	sensor->subscribe("Engagement_Service_POSITION");


	control = new Control_();
	control->setName("control");
	control->setLaunchTime(this->getLaunchTime());
	control->setExitSimulationTime(this->getExitSimulationTime());
	simulator->getEngagement()->registerModule(control);



	 // Connections are initialized here

	ServiceFunction *handler;
	Connection *conn;

	handler = new ServiceFunction();
	FlightMechanics_ * flightMechanics_get_beta_2_aerodynamics = (FlightMechanics_*) flightMechanics;
	handler->double_function = std::bind(&FlightMechanics_::get_beta, flightMechanics_get_beta_2_aerodynamics);
	conn = new Connection(flightMechanics, *handler);
	aerodynamics->addConnection("beta", conn);

	handler = new ServiceFunction();
	FlightMechanics_ * flightMechanics_get_position_2_sensor = (FlightMechanics_*) flightMechanics;
	handler->Matrix_function = std::bind(&FlightMechanics_::get_position, flightMechanics_get_position_2_sensor);
	conn = new Connection(flightMechanics, *handler);
	sensor->addConnection("position", conn);

	handler = new ServiceFunction();
	FlightMechanics_ * flightMechanics_get_position_2_massInertia = (FlightMechanics_*) flightMechanics;
	handler->Matrix_function = std::bind(&FlightMechanics_::get_position, flightMechanics_get_position_2_massInertia);
	conn = new Connection(flightMechanics, *handler);
	massInertia->addConnection("pos_BE_B", conn);

	handler = new ServiceFunction();
	Control_ * control_get_externalForce_2_flightMechanics = (Control_*) control;
	handler->Matrix_function = std::bind(&Control_::get_externalForce, control_get_externalForce_2_flightMechanics);
	conn = new Connection(control, *handler);
	flightMechanics->addConnection("externalForces", conn);

	handler = new ServiceFunction();
	MassInertia * massInertia_get_xcg_2_aerodynamics = (MassInertia*) massInertia;
	handler->Matrix_function = std::bind(&MassInertia::get_xcg, massInertia_get_xcg_2_aerodynamics);
	conn = new Connection(massInertia, *handler);
	aerodynamics->addConnection("xcg", conn);

	handler = new ServiceFunction();
	FlightMechanics_ * flightMechanics_get_DCM_2_gravity = (FlightMechanics_*) flightMechanics;
	handler->Matrix_function = std::bind(&FlightMechanics_::get_DCM, flightMechanics_get_DCM_2_gravity);
	conn = new Connection(flightMechanics, *handler);
	gravity->addConnection("DCM", conn);

	handler = new ServiceFunction();
	Aerodynamics * aerodynamics_get_aero_moment_2_flightMechanics = (Aerodynamics*) aerodynamics;
	handler->Matrix_function = std::bind(&Aerodynamics::get_aero_moment, aerodynamics_get_aero_moment_2_flightMechanics);
	conn = new Connection(aerodynamics, *handler);
	flightMechanics->addConnection("aero_moment", conn);

	handler = new ServiceFunction();
	FlightMechanics_ * flightMechanics_get_velocity_2_aerodynamics = (FlightMechanics_*) flightMechanics;
	handler->Matrix_function = std::bind(&FlightMechanics_::get_velocity, flightMechanics_get_velocity_2_aerodynamics);
	conn = new Connection(flightMechanics, *handler);
	aerodynamics->addConnection("velocity", conn);

	handler = new ServiceFunction();
	MassInertia * massInertia_get_inertia_dot_2_flightMechanics = (MassInertia*) massInertia;
	handler->Matrix_function = std::bind(&MassInertia::get_inertia_dot, massInertia_get_inertia_dot_2_flightMechanics);
	conn = new Connection(massInertia, *handler);
	flightMechanics->addConnection("inertia_dot", conn);

	handler = new ServiceFunction();
	Sensor * sensor_get_sensorData_2_control = (Sensor*) sensor;
	handler->Matrix_function = std::bind(&Sensor::get_sensorData, sensor_get_sensorData_2_control);
	conn = new Connection(sensor, *handler);
	control->addConnection("sensorData", conn);

	handler = new ServiceFunction();
	Aerodynamics * aerodynamics_get_aero_force_2_flightMechanics = (Aerodynamics*) aerodynamics;
	handler->Matrix_function = std::bind(&Aerodynamics::get_aero_force, aerodynamics_get_aero_force_2_flightMechanics);
	conn = new Connection(aerodynamics, *handler);
	flightMechanics->addConnection("aero_force", conn);

	handler = new ServiceFunction();
	FlightMechanics_ * flightMechanics_get_orientation_2_sensor = (FlightMechanics_*) flightMechanics;
	handler->Matrix_function = std::bind(&FlightMechanics_::get_orientation, flightMechanics_get_orientation_2_sensor);
	conn = new Connection(flightMechanics, *handler);
	sensor->addConnection("orientation", conn);

	handler = new ServiceFunction();
	MassInertia * massInertia_get_xcg_2_propulsion = (MassInertia*) massInertia;
	handler->Matrix_function = std::bind(&MassInertia::get_xcg, massInertia_get_xcg_2_propulsion);
	conn = new Connection(massInertia, *handler);
	propulsion->addConnection("xcg", conn);

	handler = new ServiceFunction();
	Propulsion * propulsion_get_prop_moment_2_flightMechanics = (Propulsion*) propulsion;
	handler->Matrix_function = std::bind(&Propulsion::get_prop_moment, propulsion_get_prop_moment_2_flightMechanics);
	conn = new Connection(propulsion, *handler);
	flightMechanics->addConnection("prop_moment", conn);

	handler = new ServiceFunction();
	FlightMechanics_ * flightMechanics_get_angularVelocity_2_aerodynamics = (FlightMechanics_*) flightMechanics;
	handler->Matrix_function = std::bind(&FlightMechanics_::get_angularVelocity, flightMechanics_get_angularVelocity_2_aerodynamics);
	conn = new Connection(flightMechanics, *handler);
	aerodynamics->addConnection("angularVelocity", conn);

	handler = new ServiceFunction();
	Propulsion * propulsion_get_prop_force_2_flightMechanics = (Propulsion*) propulsion;
	handler->Matrix_function = std::bind(&Propulsion::get_prop_force, propulsion_get_prop_force_2_flightMechanics);
	conn = new Connection(propulsion, *handler);
	flightMechanics->addConnection("prop_force", conn);

	handler = new ServiceFunction();
	MassInertia * massInertia_get_inertia_2_flightMechanics = (MassInertia*) massInertia;
	handler->Matrix_function = std::bind(&MassInertia::get_inertia, massInertia_get_inertia_2_flightMechanics);
	conn = new Connection(massInertia, *handler);
	flightMechanics->addConnection("inertia", conn);

	handler = new ServiceFunction();
	MassInertia * massInertia_get_mass_2_gravity = (MassInertia*) massInertia;
	handler->double_function = std::bind(&MassInertia::get_mass, massInertia_get_mass_2_gravity);
	conn = new Connection(massInertia, *handler);
	gravity->addConnection("mass", conn);

	handler = new ServiceFunction();
	FlightMechanics_ * flightMechanics_get_alpha_2_aerodynamics = (FlightMechanics_*) flightMechanics;
	handler->double_function = std::bind(&FlightMechanics_::get_alpha, flightMechanics_get_alpha_2_aerodynamics);
	conn = new Connection(flightMechanics, *handler);
	aerodynamics->addConnection("alpha", conn);

	handler = new ServiceFunction();
	MassInertia * massInertia_get_mass_2_flightMechanics = (MassInertia*) massInertia;
	handler->double_function = std::bind(&MassInertia::get_mass, massInertia_get_mass_2_flightMechanics);
	conn = new Connection(massInertia, *handler);
	flightMechanics->addConnection("mass", conn);

	handler = new ServiceFunction();
	Gravity * gravity_get_gravitational_force_2_flightMechanics = (Gravity*) gravity;
	handler->Matrix_function = std::bind(&Gravity::get_gravitational_force, gravity_get_gravitational_force_2_flightMechanics);
	conn = new Connection(gravity, *handler);
	flightMechanics->addConnection("gravitational_force", conn);




	addEntity(flightMechanics);
	addEntity(aerodynamics);
	addEntity(gravity);
	addEntity(massInertia);
	addEntity(sensor);
	addEntity(propulsion);
	addEntity(control);



	massInertia->initialize();
	aerodynamics->initialize();
	gravity->initialize();
	propulsion->initialize();
	flightMechanics->initialize();
	sensor->initialize();
	control->initialize();

}

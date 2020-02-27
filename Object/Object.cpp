/*
 * Object.cpp
 *
 * Created on : 20-01-2020 09:00
 *	   Author : eren.dere
 */

#include "Object.h"
#include <Utils.h>
#include <Simulator.h>

extern Simulator *simulator;

Object::Object() {

}

Object::~Object() {
	// TODO Auto-generated destructor stub
}


void Object::createModules() {

/**
 * TODO: Ek kodlar buraya yazilabilir
 */

	/**
	 * Bu kisimda sadece moduller tanitiliyor.
	 * Sirasi onemli degil.
	 */
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


	flightMechanics = new FlightMechanics();
	flightMechanics->setName("flightMechanics");
	flightMechanics->setLaunchTime(this->getLaunchTime());
	flightMechanics->setExitSimulationTime(this->getExitSimulationTime());
	simulator->getEngagement()->registerModule(flightMechanics);
	flightMechanics->subscribe(EngagementServiceType::POSITION);



	/**
	 * 	Connect agents and modules
	 * 	Burada Connectionlar belirleniyor
	 */

	ServiceFunction *handler;
	Connection *conn;

	handler = new ServiceFunction();
	FlightMechanics * flightMechanics_get_boost_coast_2_aerodynamics = (FlightMechanics*) flightMechanics;
	handler->bool_function = std::bind(&FlightMechanics::get_boost_coast, flightMechanics_get_boost_coast_2_aerodynamics);
	conn = new Connection(flightMechanics, *handler);
	aerodynamics->addConnection("boost_coast", conn);

	handler = new ServiceFunction();
	Aerodynamics * aerodynamics_get_aero_moment_2_flightMechanics = (Aerodynamics*) aerodynamics;
	handler->Matrix_function = std::bind(&Aerodynamics::get_aero_moment, aerodynamics_get_aero_moment_2_flightMechanics);
	conn = new Connection(aerodynamics, *handler);
	flightMechanics->addConnection("aero_moment", conn);

	handler = new ServiceFunction();
	Gravity * gravity_get_gravitational_force_2_flightMechanics = (Gravity*) gravity;
	handler->Matrix_function = std::bind(&Gravity::get_gravitational_force, gravity_get_gravitational_force_2_flightMechanics);
	conn = new Connection(gravity, *handler);
	flightMechanics->addConnection("gravitational_force", conn);

	handler = new ServiceFunction();
	Propulsion * propulsion_get_prop_moment_2_flightMechanics = (Propulsion*) propulsion;
	handler->Matrix_function = std::bind(&Propulsion::get_prop_moment, propulsion_get_prop_moment_2_flightMechanics);
	conn = new Connection(propulsion, *handler);
	flightMechanics->addConnection("prop_moment", conn);

	handler = new ServiceFunction();
	FlightMechanics * flightMechanics_get_DCM_be_2_gravity = (FlightMechanics*) flightMechanics;
	handler->Matrix_function = std::bind(&FlightMechanics::get_DCM_be, flightMechanics_get_DCM_be_2_gravity);
	conn = new Connection(flightMechanics, *handler);
	gravity->addConnection("DCM_be", conn);

	handler = new ServiceFunction();
	FlightMechanics * flightMechanics_get_vel_BE_B_2_aerodynamics = (FlightMechanics*) flightMechanics;
	handler->Matrix_function = std::bind(&FlightMechanics::get_vel_BE_B, flightMechanics_get_vel_BE_B_2_aerodynamics);
	conn = new Connection(flightMechanics, *handler);
	aerodynamics->addConnection("vel_BE_B", conn);

	handler = new ServiceFunction();
	MassInertia * massInertia_get_mass_2_flightMechanics = (MassInertia*) massInertia;
	handler->double_function = std::bind(&MassInertia::get_mass, massInertia_get_mass_2_flightMechanics);
	conn = new Connection(massInertia, *handler);
	flightMechanics->addConnection("mass", conn);

	handler = new ServiceFunction();
	Aerodynamics * aerodynamics_get_aero_force_2_flightMechanics = (Aerodynamics*) aerodynamics;
	handler->Matrix_function = std::bind(&Aerodynamics::get_aero_force, aerodynamics_get_aero_force_2_flightMechanics);
	conn = new Connection(aerodynamics, *handler);
	flightMechanics->addConnection("aero_force", conn);

	handler = new ServiceFunction();
	FlightMechanics * flightMechanics_get_beta_2_aerodynamics = (FlightMechanics*) flightMechanics;
	handler->double_function = std::bind(&FlightMechanics::get_beta, flightMechanics_get_beta_2_aerodynamics);
	conn = new Connection(flightMechanics, *handler);
	aerodynamics->addConnection("beta", conn);

	handler = new ServiceFunction();
	FlightMechanics * flightMechanics_get_pos_BE_B_2_massInertia = (FlightMechanics*) flightMechanics;
	handler->Matrix_function = std::bind(&FlightMechanics::get_pos_BE_B, flightMechanics_get_pos_BE_B_2_massInertia);
	conn = new Connection(flightMechanics, *handler);
	massInertia->addConnection("pos_BE_B", conn);

	handler = new ServiceFunction();
	MassInertia * massInertia_get_inertia_dot_2_flightMechanics = (MassInertia*) massInertia;
	handler->Matrix_function = std::bind(&MassInertia::get_inertia_dot, massInertia_get_inertia_dot_2_flightMechanics);
	conn = new Connection(massInertia, *handler);
	flightMechanics->addConnection("inertia_dot", conn);

	handler = new ServiceFunction();
	MassInertia * massInertia_get_mass_2_gravity = (MassInertia*) massInertia;
	handler->double_function = std::bind(&MassInertia::get_mass, massInertia_get_mass_2_gravity);
	conn = new Connection(massInertia, *handler);
	gravity->addConnection("mass", conn);

	handler = new ServiceFunction();
	MassInertia * massInertia_get_xcg_2_propulsion = (MassInertia*) massInertia;
	handler->Matrix_function = std::bind(&MassInertia::get_xcg, massInertia_get_xcg_2_propulsion);
	conn = new Connection(massInertia, *handler);
	propulsion->addConnection("xcg", conn);

	handler = new ServiceFunction();
	FlightMechanics * flightMechanics_get_alpha_2_aerodynamics = (FlightMechanics*) flightMechanics;
	handler->double_function = std::bind(&FlightMechanics::get_alpha, flightMechanics_get_alpha_2_aerodynamics);
	conn = new Connection(flightMechanics, *handler);
	aerodynamics->addConnection("alpha", conn);

	handler = new ServiceFunction();
	MassInertia * massInertia_get_xcg_2_aerodynamics = (MassInertia*) massInertia;
	handler->Matrix_function = std::bind(&MassInertia::get_xcg, massInertia_get_xcg_2_aerodynamics);
	conn = new Connection(massInertia, *handler);
	aerodynamics->addConnection("xcg", conn);

	handler = new ServiceFunction();
	FlightMechanics * flightMechanics_get_om_BI_B_2_aerodynamics = (FlightMechanics*) flightMechanics;
	handler->Matrix_function = std::bind(&FlightMechanics::get_om_BI_B, flightMechanics_get_om_BI_B_2_aerodynamics);
	conn = new Connection(flightMechanics, *handler);
	aerodynamics->addConnection("om_BI_B", conn);

	handler = new ServiceFunction();
	MassInertia * massInertia_get_inertia_2_flightMechanics = (MassInertia*) massInertia;
	handler->Matrix_function = std::bind(&MassInertia::get_inertia, massInertia_get_inertia_2_flightMechanics);
	conn = new Connection(massInertia, *handler);
	flightMechanics->addConnection("inertia", conn);

	handler = new ServiceFunction();
	Propulsion * propulsion_get_prop_force_2_flightMechanics = (Propulsion*) propulsion;
	handler->Matrix_function = std::bind(&Propulsion::get_prop_force, propulsion_get_prop_force_2_flightMechanics);
	conn = new Connection(propulsion, *handler);
	flightMechanics->addConnection("prop_force", conn);




	/**
	 * Run daki Siralama Gecerli
	 * Bu kisimda sadece Run daki siralamalar yapiliyor
	 */
	addEntity(flightMechanics);
	addEntity(aerodynamics);
	addEntity(gravity);
	addEntity(massInertia);
	addEntity(propulsion);



	massInertia->initialize();
	aerodynamics->initialize();
	gravity->initialize();
	propulsion->initialize();
	flightMechanics->initialize();

}

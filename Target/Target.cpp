/*
 * Target.cpp
 *
 * Created on : 02-03-2020 04:01
 *	   Author : eren.dere
 */

#include "Target.h"
#include <Utils.h>
#include <Simulator.h>

extern Simulator *simulator;


Target::Target() {

}

Target::~Target() {

}



void Target::createModules() {


	posInfo = new VehicleMechanics();
	posInfo->setName("posInfo");
	posInfo->setLaunchTime(this->getLaunchTime());
	posInfo->setExitSimulationTime(this->getExitSimulationTime());
	simulator->getEngagement()->registerModule(posInfo);



	 // Connections are initialized here

	ServiceFunction *handler;
	Connection *conn;




	addEntity(posInfo);



	posInfo->initialize();

}

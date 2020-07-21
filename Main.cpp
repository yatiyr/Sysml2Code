/*
 * Main.cpp
 *
 * Created on : 02-03-2020 04:01
 *	   Author : eren.dere
 */

#include <Simulator.h>
#include "AirVehicle.h"
#include "Target.h"

void readSimulationData();

Simulator *simulator;

int main(){
	simulator = new Simulator();
	simulator->readConfig();

	/**
	 * Create entities and run
	 */
	AirVehicle * airvehicle1 = new AirVehicle();
	airvehicle1->setName("airvehicle1");
	airvehicle1->setLaunchTime(0);
	airvehicle1->createModules();
	simulator->addEntity(airvehicle1);

	Target * target1 = new Target();
	target1->setName("target1");
	target1->setLaunchTime(0);
	target1->createModules();
	simulator->addEntity(target1);

	simulator->run();

	return 0;	

}

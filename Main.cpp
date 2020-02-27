/*
 * Main.cpp
 *
 * Created on : 20-01-2020 09:00
 *	   Author : eren.dere
 */

#include <Simulator.h>
#include "Object.h"
#include "Target.h"

void readSimulationData();

Simulator *simulator;

int main(){
	simulator = new Simulator();
	simulator->readConfig();

	/**
	 * Varliklari yarat ve baslat
	 */
	Object * object1 = new Object();
	object1->setName("object1");
	object1->setLaunchTime(0);
	object1->createModules();
	simulator->addEntity(object1);

	Target * target1 = new Target();
	target1->setName("target1");
	target1->setLaunchTime(0);
	target1->createModules();
	simulator->addEntity(target1);

	simulator->run();

	return 0;	

}
